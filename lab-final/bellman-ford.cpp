#include <iostream>
#include <vector>
#include <climits>   // INT_MAX
#include <utility>   // std::pair

using namespace std;

struct Node {
    int p;  // parent
    int d;  // distance
    Node() : p(-1), d(INT_MAX) {}
};

typedef pair<int,int> Edge;     // (v, w)
typedef vector<Edge> edges_t;   // adjacency list of (v,w)
typedef vector<edges_t> graph_t;

// Bellman–Ford: returns true if no negative cycle reachable from src
bool bellmanFord(const graph_t& graph, int src, int dst, vector<int>& path) {
    int n = (int)graph.size();
    vector<Node> nodes(n);

    // Initialization
    nodes[src].d = 0;

    // Relax edges |V| - 1 times
    for (int it = 0; it < n - 1; ++it) {
        bool changed = false;
        for (int u = 0; u < n; ++u) {
            const edges_t& adj = graph[u];
            for (size_t k = 0; k < adj.size(); ++k) {
                int v = adj[k].first;
                int w = adj[k].second;
                if (nodes[u].d != INT_MAX && nodes[v].d > nodes[u].d + w) {
                    nodes[v].d = nodes[u].d + w;
                    nodes[v].p = u;
                    changed = true;
                }
            }
        }
        if (!changed) break; // optional early exit
    }

    // Check for negative cycles
    for (int u = 0; u < n; ++u) {
        const edges_t& adj = graph[u];
        for (size_t k = 0; k < adj.size(); ++k) {
            int v = adj[k].first;
            int w = adj[k].second;
            if (nodes[u].d != INT_MAX && nodes[v].d > nodes[u].d + w) {
                return false; // negative cycle reachable from src
            }
        }
    }

    // Unreachable destination
    if (nodes[dst].d == INT_MAX) {
        return false;
    }

    // Reconstruct path src -> dst
    int cur = dst;
    while (cur != -1) {
        path.insert(path.begin(), cur);
        cur = nodes[cur].p;
    }

    return true;
}

int main() {
    graph_t graph(5);  // 5 vertices: 0..4

    // Build adjacency lists (u -> (v, w))
    graph[0].push_back(Edge(1, 6));
    graph[0].push_back(Edge(3, 7));

    graph[1].push_back(Edge(2, 5));
    graph[1].push_back(Edge(3, 8));
    graph[1].push_back(Edge(4, -4));

    graph[2].push_back(Edge(1, -2));

    graph[3].push_back(Edge(2, -3));
    graph[3].push_back(Edge(4, 9));

    graph[4].push_back(Edge(0, 2));
    graph[4].push_back(Edge(2, 7));

    vector<int> path;
    if (bellmanFord(graph, 0, 2, path)) {   // shortest path 0 -> 2
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "negative cycle detected or no path\n";
    }

    return 0;
}
