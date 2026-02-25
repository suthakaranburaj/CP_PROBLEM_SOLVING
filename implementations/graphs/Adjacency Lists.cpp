#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    bool directed;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices, bool isDirected = false) {
        V = vertices;
        directed = isDirected;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight = 1) {
        adj[u].push_back({v, weight});
        if (!directed) adj[v].push_back({u, weight});
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto edge : adj[i]) {
                cout << "(" << edge.first << ", w=" << edge.second << ") ";
            }
            cout << endl;
        }
    }

    // ----------------------------
    // Breadth First Search (BFS)
    // ----------------------------
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from " << start << ": ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto edge : adj[node]) {
                int neighbour = edge.first;
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        cout << endl;
    }

    // ----------------------------
    // Depth First Search (DFS)
    // ----------------------------
    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto edge : adj[node]) {
            int neighbour = edge.first;
            if (!visited[neighbour])
                DFSUtil(neighbour, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS starting from " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.printGraph();

    cout << endl;
    g.BFS(0);
    g.DFS(0);

    return 0;
}
