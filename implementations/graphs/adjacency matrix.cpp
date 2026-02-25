#include <bits/stdc++.h>
using namespace std;

class GraphMatrix {
private:
    int V;
    bool directed;
    vector<vector<int>> matrix;

public:
    GraphMatrix(int vertices, bool isDirected = false) {
        V = vertices;
        directed = isDirected;
        matrix.assign(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight = 1) {
        matrix[u][v] = weight;
        if (!directed) matrix[v][u] = weight;
    }

    void printGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GraphMatrix g(4, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();
    return 0;
}
