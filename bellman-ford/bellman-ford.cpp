#include <iostream>
using namespace std;

#define INF 1000000000

// Relax(u, v, w)
void relax(int u, int v, int w, int d[], int pi[])
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
    }
}

// Initialize-Single-Source(G, s)
void initialize(int d[], int pi[], int V, int s)
{
    for (int i = 0; i < V; i++)
    {
        d[i] = INF;
        pi[i] = -1; // NIL (no predecessor)
    }
    d[s] = 0;
}

// Bellman-Ford(G, w, s)
bool bellmanFord(int edges[][3], int V, int E, int s, int d[], int pi[])
{
    initialize(d, pi, V, s);

    // Relax all edges |V|-1 times
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            relax(u, v, w, d, pi);
        }
    }

    // Check for negative cycle
    for (int j = 0; j < E; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (d[v] > d[u] + w)
            return false;
    }

    return true;
}

int main()
{
    int V, E, source;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    int edges[500][3];
    int d[100];
    int pi[100];

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "\nEnter source vertex: ";
    cin >> source;

    // Run Bellman-Ford
    if (bellmanFord(edges, V, E, source, d, pi))
    {
        cout << "\nNo negative-weight cycle detected.\n";
        cout << "Shortest distances from source " << source << ":\n";

        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " : ";
            if (d[i] == INF)
                cout << "INF\n";
            else
                cout << d[i] << "\n";
        }
    }
    else
    {
        cout << "\nNegative-weight cycle detected! Cannot compute shortest paths.\n";
    }

    return 0;
}