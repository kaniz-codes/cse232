#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

#define V 4 // Number of vertices

// Function to find the vertex with minimum key value
int minKey(int key[], bool explore[])
{
	int min = INT_MAX;
	int min_index = -1;

	for (int v = 0; v < V; v++)

		if (!explore[v] && key[v] < min)
		{
			min = key[v];
			min_index = v;
		}

	return min_index;
}

// Function to print MST
void printMST(int parent[], int graph[V][V])
{
	cout << "\nEdge \tWeight\n";
	for (int i = 0; i < V; i++)
	{
		if (parent[i] != -1)
			cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
	}
}

// Prim's MST algorithm
void primMST(int graph[V][V], int r)
{
	int parent[V];	 // To store MST
	int key[V];		 // To pick minimum weight edge
	bool explore[V]; // Track included vertices

	// Initialize all keys as infinite and explore[] as false
	for (int i = 0; i < V; i++)
	{
		key[i] = INT_MAX;
		explore[i] = false;
		parent[i] = -1;
	}

	key[r] = 0; // Start from user�s chosen vertex

	// Build MST
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, explore);
		explore[u] = true;

		for (int v = 0; v < V; v++)
		{
			if (graph[u][v] != 0 && !explore[v] && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}

	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = {
		{0, 2, 4, 0},
		{2, 0, 1, 3},
		{4, 1, 0, 5},
		{0, 3, 5, 0}};
	int r;
	cout << "Enter the starting vertex (0 to " << V - 1 << "): ";
	cin >> r;

	if (r < 0 || r >= V)
	{
		cout << "Invalid source vertex!" << endl;
		return 1;
	}

	primMST(graph, r);

	return 0;
}
