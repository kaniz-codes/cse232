#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define WHITE 0
#define GRAY  1
#define BLACK 2

int color[MAX];
int d[MAX];
int f[MAX];
int pi[MAX];
int Adj[MAX][MAX];
int n; // number of vertices
int Time;

void DFS_VISIT(int u) {
    Time++;
    d[u] = Time;
    color[u] = GRAY;

    for (int v = 0; v < n; v++) {
        if (Adj[u][v] == 1 && color[v] == WHITE) {
            pi[v] = u;
            DFS_VISIT(v);
        }
    }

    color[u] = BLACK;
    Time++;
    f[u] = Time;
}

void DFS() {
    for (int u = 0; u < n; u++) {
        color[u] = WHITE;
        pi[u] = -1;
    }

    Time = 0;

    for (int u = 0; u < n; u++) {
        if (color[u] == WHITE)
            DFS_VISIT(u);
    }

    cout << "\nVertex : Discovery / Finish time\n";
    for (int i = 0; i < n; i++) {
        cout << i << " : " << d[i] << " / " << f[i] << endl;
    }
}

int main() {
    int e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Adj[i][j] = 0;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        Adj[u][v] = 1;
       // Adj[v][u] = 1; // for undirected
    }

    DFS();
}

