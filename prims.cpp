#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet, int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(vector<vector<int>> &graph, int V) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    cout << "\nEdges in MST (Prim):\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " -- " << i << " == " << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0, 2, 3, 1},
        {2, 0, 0, 6},
        {3, 0, 0, 4},
        {1, 6, 4, 0}
    };

    primMST(graph, V);
    return 0;
}
