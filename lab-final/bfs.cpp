#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS function
void BFS(vector<vector<int>> &graph, int start) {
    int n = graph.size();

    // distance array
    vector<int> dist(n, -1);

    queue<int> q;

    dist[start] = 0;    // distance to itself = 0
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // visit all neighbors
        for (int v : graph[u]) {
            if (dist[v] == -1) {  // not visited yet
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // print distances
    cout << "Node : Distance from start\n";
    for (int i = 0; i < n; i++) {
        cout << i << " : " << dist[i] << endl;
    }
}

int main() {
    int n = 6;  // number of nodes

    // Create graph with 6 nodes
    vector<vector<int>> graph(n);

    // Add edges (undirected)
    graph[0].push_back(1);
    graph[0].push_back(3);

    graph[1].push_back(0);
    graph[1].push_back(4);

    graph[2].push_back(4);
    graph[2].push_back(5);

    graph[3].push_back(0);

    graph[4].push_back(1);
    graph[4].push_back(2);
    graph[4].push_back(5);

    graph[5].push_back(2);
    graph[5].push_back(4);

    // Run BFS starting from node 0
    BFS(graph, 0);

    return 0;
}
