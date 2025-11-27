#include <iostream>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to find the parent of a vertex in the union-find algorithm
int findParent(int parent[], int i) {
    // If the vertex is its own parent, return the vertex
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union of two sets of vertices
void performUnion(int parent[], int x, int y) {
    // Find the parent of x and y
    int x_set = findParent(parent, x);
    int y_set = findParent(parent, y);
    // Set the parent of x to y (merge the sets)
    parent[x_set] = y_set;
}


// Function to implement heapify
void heapify(Edge arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].weight > arr[largest].weight)
        largest = l;

    if (r < n && arr[r].weight > arr[largest].weight)
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to implement heap sort
void heapSort(Edge arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to create and sort the array of edges
Edge* createAndSortEdges(int **graph, int vertices, int &edgeCount) {
    // Create a sorted array of edges
    Edge *edges = new Edge[vertices * (vertices - 1) / 2];
    edgeCount = 0;
    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            if (graph[i][j] != -1) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }
    heapSort(edges, edgeCount);
    return edges;
}

// Function to implement Kruskal's algorithm that accepts an adjacency matrix as input
void kruskalMST(int **graph, int vertices) {
    int edgeCount;
    Edge *edges = createAndSortEdges(graph, vertices, edgeCount);

    // Allocate memory for parent array for Union-Find
    int *parent = new int[vertices];
    for (int i = 0; i < vertices; ++i)
        parent[i] = i; // Each vertex is initially in its own set

    // Initialize variables for MST
    Edge *result = new Edge[vertices - 1]; // MST has (vertices - 1) edges
    int resultIndex = 0, edgeIndex = 0;
    int minCost = 0;

    // Apply Kruskal's algorithm
    while (resultIndex < vertices - 1 && edgeIndex < edgeCount) {
        // Get the next edge from the sorted array
        Edge nextEdge = edges[edgeIndex++];

        // Find the parent of the source and destination vertices
        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        // If adding this edge does not create a cycle in the MST
        if (x != y) {
            // Add the edge to the MST
            result[resultIndex++] = nextEdge;
            // Union the sets containing the source and destination vertices
            performUnion(parent, x, y);
            // Update minimum cost
            minCost += nextEdge.weight;
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 0; i < vertices - 1; ++i) {
        cout << result[i].src + 1 << "--" << result[i].dest + 1 << " Weight: " << result[i].weight << endl;
    }

    // Print the minimum cost
    cout << "Minimum Cost: " << minCost << endl;

    // Deallocate memory
    delete[] edges;
    delete[] parent;
    delete[] result;
}


// Function to create and store the graph in adjacency matrix
void takeUserInputAndCreateAdjacencyMatrix(int **&graph, int vertices) {
    // Allocate memory for the adjacency matrix
    graph = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        graph[i] = new int[vertices];
        // Initialize the adjacency matrix with -1 (no edges between vertices)
        for (int j = 0; j < vertices; ++j) {
            graph[i][j] = -1;
        }
    }

    // Prompt user to enter the number of edges
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Check if the number of edges is valid
    if (edges > (vertices * (vertices - 1) / 2)) {
        cerr << "Error: Invalid input. Number of edges exceeds the maximum possible for the given number of vertices." << endl;
        exit(1); // Exit program with error status
    }

    // Prompt user to enter the edges
    cout << "Enter the edges in the format (firstVertex secondVertex Weight) pairs, where vertex should be between 1 and " << vertices << ":" << endl;
    for (int i = 0; i < edges; ++i) {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;

        // Check if the vertices are within the valid range
        if (vertex1 < 1 || vertex1 > vertices || vertex2 < 1 || vertex2 > vertices) {
            cerr << "Error: Invalid input. Vertices should be between 1 and " << vertices << endl;
            exit(2); // Exit program with error status
        }

        // Ignore self loops
        if (vertex1 != vertex2) {
            // Store the edge weight in both directions
            graph[vertex1 - 1][vertex2 - 1] = weight;
            graph[vertex2 - 1][vertex1 - 1] = weight;
        }
    }
}

// Function to deallocate memory for the graph
void deleteGraph(int **&graph, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
}

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int **graph = nullptr;

    // Create the graph
    takeUserInputAndCreateAdjacencyMatrix(graph, vertices);

    // Call Kruskal's MST algorithm that accepts an adjacency matrix as input
    kruskalMST(graph, vertices);

    // Deallocate memory for the graph
    deleteGraph(graph, vertices);

    return 0;
}