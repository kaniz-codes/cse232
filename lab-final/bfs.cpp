#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX];    // stores WHITE/GRAY/BLACK
int d[MAX];        // distance array
int pi[MAX];       // parent array
int Adj[MAX][MAX]; // adjacency matrix
int n;             // number of vertices

void BFS(int s)
{
    for (int u = 0; u < n; u++)
    {
        color[u] = WHITE;
        d[u] = INT_MAX;
        pi[u] = -1;
    }

    color[s] = GRAY;
    d[s] = 0;
    pi[s] = -1;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v = 0; v < n; v++)
        {
            if (Adj[u][v] == 1 && color[v] == WHITE)
            {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                pi[v] = u;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }

    cout << "\nVertex : Distance from source\n";
    for (int i = 0; i < n; i++)
    {
        if (d[i] == INT_MAX)
            cout << i << " : " << -1 << endl;
        else
            cout << i << " : " << d[i] << endl;
    }
}

int main()
{
    int e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Adj[i][j] = 0;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u][v] = 1;
        Adj[v][u] = 1; // for undirected
    }

    int s;
    cout << "Enter source vertex: ";
    cin >> s;

    BFS(s);
}
