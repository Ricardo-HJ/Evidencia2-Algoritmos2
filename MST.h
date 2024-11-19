//Ricardo Hernandez - A00837337
//Last edited: 18/11/24
#ifndef MST_HPP
#define MST_HPP

#include "utils.h"

using namespace std;

//Time complexity: O(n)
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end());
    vector<Edge> result;
    DisjointSet ds(V);
    for (Edge e : edges) {
        if (ds.find(e.src) != ds.find(e.dest)) {
            ds.unite(e.src, e.dest);
            result.push_back(e);
        }
    }
    return result;
}

//Time complexity: O(n^2)
void MST(stringstream &output, int matrix[nMAX][nMAX], bool matrixBool[nMAX][nMAX], vector<Node>& nodes, int n) {
    vector<Edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] > 0 && !matrixBool[i][j]) {
                edges.push_back({i, j, matrix[i][j]});
            }
        }
    }

    vector<Edge> mst = kruskalMST(edges, n);

    output << "-------------------" << endl;
    output << "1 - Cableado óptimo de nueva conexión." << endl << endl;
    int totalCost = 0;
    int edgesAdded = 0;
    for (const Edge& e : mst) {
        if (edgesAdded < n - 2) {
            output << nodes[e.src].name << " - " << nodes[e.dest].name << " " << e.weight << endl;
            totalCost += e.weight;
            edgesAdded++;
        }
    }
    output << "\nCosto Total: " << totalCost << endl;
}

#endif