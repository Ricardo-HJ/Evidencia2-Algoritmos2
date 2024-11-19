//Ricardo Hernandez - A00837337
//Last edited: 18/11/24
#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <queue>
#include <map>

#define nMAX 31

using namespace std;

struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct Node {
    int id;
    string name;
    int x;
    int y;
    bool central;
};

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else { parent[py] = px; rank[px]++; }
    }
};

//Time complexity: O(n^3)
vector<vector<int>> fillDist(int matrix[nMAX][nMAX], int n, vector<vector<int>>& paths) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    paths.resize(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                dist[i][j] = matrix[i][j];
                paths[i][j] = i;
            }
            if (i == j) dist[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    paths[i][j] = paths[k][j];
                }
            }
        }
    }

    return dist;
}

//Time complexity: O(n)
void readInput(vector<Node>& nodes, vector<Node>& futureNodes, int matrix[nMAX][nMAX], bool matrixBool[nMAX][nMAX], vector<vector<int>>& dist, vector<vector<int>>& paths, int& n) {
    int nodesN, edges, edgesNew, nodesNew;
    map<string, int> nameID;

    cin >> nodesN >> edges >> edgesNew >> nodesNew;

    for (int i = 0; i < nodesN; i++) {
        Node node;
        node.id = i;
        cin >> node.name >> node.x >> node.y >> node.central;
        nodes.push_back(node);
        nameID[node.name] = i;
    }

    for (int i = 0; i < edges; i++) {
        string e1, e2;
        int weight, id1, id2;
        cin >> e1 >> e2 >> weight;

        id1 = nameID[e1];
        id2 = nameID[e2];

        matrix[id1][id2] = weight;
        matrix[id2][id1] = weight;
    }

    for (int i = 0; i < edgesNew; i++) {
        string e1, e2;
        int id1, id2;

        cin >> e1 >> e2;

        id1 = nameID[e1];
        id2 = nameID[e2];

        matrixBool[id1][id2] = 1;
        matrixBool[id2][id1] = 1;
    }

    for (int i = 0; i < nodesNew; i++) {
        Node node;
        cin >> node.name >> node.x >> node.y;
        futureNodes.push_back(node);
    }

    n = nodes.size();    
    dist = fillDist(matrix, n, paths);
}

//Time complexity: O(n)
int findNearestNeighbor(const vector<Node>& nodes, int x, int y) {
    int nearest = 0;
    double minDist = numeric_limits<double>::max();
    for (int i = 0; i < nodes.size(); i++) {
        double dist = sqrt(pow(nodes[i].x - x, 2) + pow(nodes[i].y - y, 2));
        if (dist < minDist) {
            minDist = dist;
            nearest = i;
        }
    }
    return nearest;
}

//Time complexity: O(n^3)
void centrales(stringstream& output, vector<Node>& nodes, int matrix[nMAX][nMAX], const vector<vector<int>>& dist, const vector<vector<int>>& paths, int n) {
    output << "-------------------" << endl;
    output << "3 - Caminos más cortos entre centrales.\n" << endl;

    for (int i = 0; i < n; i++) {
        if (nodes[i].central) {
            for (int j = i + 1; j < n; j++) {
                if (nodes[j].central) {
                    vector<int> path;
                    for (int at = j; at != i; at = paths[i][at]) {
                        path.push_back(at);
                    }
                    path.push_back(i);
                    reverse(path.begin(), path.end());

                    for (size_t k = 0; k < path.size(); ++k) {
                        output << nodes[path[k]].name;
                        if (k < path.size() - 1) {
                            output << " - ";
                        }
                    }

                    output << " (" << dist[i][j] << ")" << endl;
                }
            }
        }
    }
    output << endl;
}

//Time complexity: O(n)
void nuevas(stringstream &output, vector<Node>& nodes, vector<Node>& futureNodes) {
    output << "-------------------" << endl;
    output << "4 - Conexión de nuevas colonias.\n" << endl;
    for (const Node& newNode : futureNodes) {
        int nearest = findNearestNeighbor(nodes, newNode.x, newNode.y);
        output << newNode.name;
        output << " debe conectarse con " << nodes[nearest].name << endl;
    }
    output << "\n-------------------";
}

#endif