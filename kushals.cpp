#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Compare function to sort edges
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find function for Union-Find
int findParent(int v, vector<int> &parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

// Union function for Union-Find
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal’s Algorithm
void kruskalMST(vector<Edge> &edges, int V) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> result;
    int totalWeight = 0;

    for (auto &edge : edges) {
        int u = findParent(edge.src, parent);
        int v = findParent(edge.dest, parent);

        if (u != v) {
            result.push_back(edge);
            totalWeight += edge.weight;
            unionSet(u, v, parent, rank);
        }
    }

    cout << "\nEdges in MST (Kruskal):\n";
    for (auto &edge : result)
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;

    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    int V = 4; // number of vertices
    vector<Edge> edges = {
        {0, 1, 2}, {0, 2, 3}, {0, 3, 1}, {2, 3, 4}, {1, 3, 6}
    };

    kruskalMST(edges, V);
    return 0;
}
