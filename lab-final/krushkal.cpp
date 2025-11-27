#include <bits/stdc++.h>
using namespace std;

#define MAX 100

// Structure to store an edge
struct Edge
{
    int u, v, w;
};

// Disjoint Set (Union-Find) helper arrays
int parent[MAX];
int rankArr[MAX];

// MAKE-SET(v)
void MAKE_SET(int v)
{
    parent[v] = v;
    rankArr[v] = 0;
}

// FIND-SET(v)
int FIND_SET(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = FIND_SET(parent[v]); // path compression
}

// UNION(u, v)
void UNION(int u, int v)
{
    int rootU = FIND_SET(u);
    int rootV = FIND_SET(v);

    if (rootU != rootV)
    {
        if (rankArr[rootU] < rankArr[rootV])
            parent[rootU] = rootV;
        else if (rankArr[rootU] > rankArr[rootV])
            parent[rootV] = rootU;
        else
        {
            parent[rootV] = rootU;
            rankArr[rootU]++;
        }
    }
}

// MST-KRUSKAL(G, w)
void MST_KRUSKAL(Edge edges[], int V, int E)
{
    Edge A[MAX]; // to store MST edges
    int edgeCount = 0;
    int totalWeight = 0;

    // Step 2: Initialize sets for each vertex
    for (int v = 0; v < V; v++)
        MAKE_SET(v);

    // Step 4: Sort edges in non-decreasing order of weight
    sort(edges, edges + E, [](Edge a, Edge b) { return a.w < b.w; });

    // Step 5–8: Process each edge
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (FIND_SET(u) != FIND_SET(v))
        {
            A[edgeCount++] = edges[i];
            totalWeight += edges[i].w;
            UNION(u, v);
        }
    }

    // Step 9: Print MST
    cout << "\nEdge \tWeight\n";
    for (int i = 0; i < edgeCount; i++)
        cout << A[i].u << " - " << A[i].v << "\t" << A[i].w << "\n";

    cout << "Total Weight of MST = " << totalWeight << endl;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[MAX];

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    MST_KRUSKAL(edges, V, E);

    return 0;
}