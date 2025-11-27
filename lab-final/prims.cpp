#include <iostream>
using namespace std;

int main()
{

	// Number of vertices
	int V = 5;

	// Hardcoded adjacency matrix
	// 0 means no edge
	int graph[5][5] = {
		{0, 2, 0, 6, 0},
		{2, 0, 3, 8, 5},
		{0, 3, 0, 0, 7},
		{6, 8, 0, 0, 9},
		{0, 5, 7, 9, 0}};

	int parent[5]; // To store MST
	int key[5];	   // To store minimum edge weight
	bool inMST[5]; // To check if added to MST

	// Initialize all keys as infinity and inMST as false
	for (int i = 0; i < V; i++)
	{
		key[i] = 1000000;
		inMST[i] = false;
	}

	// Start from vertex 0
	key[0] = 0;
	parent[0] = -1;

	// Prim's Algorithm
	for (int count = 0; count < V - 1; count++)
	{

		// Pick the minimum key vertex not yet in MST
		int minKey = 1000000;
		int u = -1;

		for (int v = 0; v < V; v++)
		{
			if (!inMST[v] && key[v] < minKey)
			{
				minKey = key[v];
				u = v;
			}
		}

		// Add chosen vertex to MST
		inMST[u] = true;

		// Update its adjacent vertices
		for (int v = 0; v < V; v++)
		{
			if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}

	// Print MST result
	int totalWeight = 0;
	cout << "Edges in MST:\n";
	for (int i = 1; i < V; i++)
	{
		cout << parent[i] << " - " << i << "  (weight = " << graph[i][parent[i]] << ")\n";
		totalWeight += graph[i][parent[i]];
	}

	cout << "Total Weight of MST = " << totalWeight << endl;

	return 0;
}
