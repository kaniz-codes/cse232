#include <iostream>
using namespace std;

#define INF 1000000000


void relax(int u, int v, int w, int d[], int pi[])
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pi[v] = u;
    }
}


void initialize(int d[], int pi[], int V, int s)
{
    for (int i = 0; i < V; i++)
    {
        d[i] = INF;
        pi[i] = -1;
    }
    d[s] = 0;
}


int extractMin(bool visited[], int d[], int V)
{
    int minDist = INF;
    int index = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && d[i] < minDist)
        {
            minDist = d[i];
            index = i;
        }
    }

    return index;
}


void dijkstra(int adj[][100], int weight[][100], int V, int s, int d[], int pi[])
{
    bool visited[100] = {false};

    initialize(d, pi, V, s);

    for (int i = 0; i < V; i++)
    {
        int u = extractMin(visited, d, V);
        if (u == -1)
            return;

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] == 1)
                relax(u, v, weight[u][v], d, pi);
        }
    }
}

int main()
{
    int V, E, source;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    int adj[100][100] = {0};
    int weight[100][100] = {0};
    int d[100];
    int pi[100];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u][v] = 1;
        weight[u][v] = w;
    }

    cout << "\nEnter source vertex: ";
    cin >> source;

    dijkstra(adj, weight, V, source, d, pi);

    cout << "\nShortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << " : ";
        if (d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << "\n";
    }
}