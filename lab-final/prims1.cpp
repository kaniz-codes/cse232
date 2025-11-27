#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

// Function to extract the vertex with the minimum key value
int EXTRACT_MIN(int key[], bool Q[], int n)
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++)
        if (Q[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Function that implements MST-PRIM(G, w, r)
void MST_PRIM(int G[MAX][MAX], int w[MAX][MAX], int r, int n)
{
    int key[MAX];
    int pi[MAX];
    bool Q[MAX];

    for (int u = 0; u < n; u++)
    {
        key[u] = INT_MAX;
        pi[u] = -1;
        Q[u] = true;
    }

    key[r] = 0;

    while (true)
    {
        int u = EXTRACT_MIN(key, Q, n);
        if (u == -1)
            break;

        Q[u] = false;

        for (int v = 0; v < n; v++)
        {
            if (G[u][v] != 0 && Q[v] && w[u][v] < key[v])
            {
                pi[v] = u;
                key[v] = w[u][v];
            }
        }
    }

    cout << "\nEdge \tWeight\n";
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (pi[i] != -1)
        {
            cout << pi[i] << " - " << i << "\t" << w[i][pi[i]] << "\n";
            total += w[i][pi[i]];
        }
    }
    cout << "Total Weight of MST = " << total << endl;
}

int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    int G[MAX][MAX] = {0};
    int w[MAX][MAX] = {0};

    cout << "Enter edges in the format: u v weight\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        G[u][v] = weight;
        G[v][u] = weight; // undirected graph
        w[u][v] = weight;
        w[v][u] = weight;
    }

    int r;
    cout << "Enter starting vertex (0-based index): ";
    cin >> r;

    MST_PRIM(G, w, r, n);

    return 0;
}