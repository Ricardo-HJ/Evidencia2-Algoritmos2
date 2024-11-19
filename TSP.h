//Ricardo Hernandez - A00837337
//Last edited: 18/11/24
#ifndef TSP_H
#define TSP_H

#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include "utils.h"

using namespace std;

//Time complexity: O(n^2)
vector<int> reconstructPath(const vector<vector<int>>& paths, int start, int end) {
    vector<int> path;
    for (int at = end; at != start; at = paths[start][at]) {
        path.push_back(at);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

//Time complexity: O(n^2)
vector<int> tsp(const vector<vector<int>>& dist, const vector<vector<int>>& paths, const vector<Node>& nodes) {
    int n = nodes.size();
    vector<int> non_central;
    for (int i = 0; i < n; i++) {
        if (!nodes[i].central) {
            non_central.push_back(i);
        }
    }
    
    int m = non_central.size();
    vector<int> tour;
    vector<bool> used(m, false);
    tour.push_back(non_central[0]);
    used[0] = true;

    for (int i = 1; i < m; i++) {
        int best = -1;
        int best_dist = numeric_limits<int>::max();
        for (int j = 0; j < m; j++) {
            if (!used[j]) {
                int d = dist[tour.back()][non_central[j]];
                if (d < best_dist) {
                    best = j;
                    best_dist = d;
                }
            }
        }
        tour.push_back(non_central[best]);
        used[best] = true;
    }
    tour.push_back(non_central[0]);  // Return to start
    return tour;
}

//Time complexity: O(n^2)
void TSP(stringstream &output, const vector<Node>& nodes, int matrix[nMAX][nMAX], const vector<vector<int>>& dist, const vector<vector<int>>& paths, int n) {
    vector<int> tour = tsp(dist, paths, nodes);
    
    output << "\n-------------------" << endl;
    output << "2 - La ruta óptima." << endl << endl;
    
    int total_cost = 0;
    for (int i = 0; i < tour.size() - 1; i++) {
        vector<int> path = reconstructPath(paths, tour[i], tour[i+1]);

        for (int j = 0; j < path.size(); j++) {

            if((j != 0) || (i == 0)) { 
                output << nodes[path[j]].name;
                if (j < path.size() - 1) {
                    output << " - ";
                } 
            }

        }

        if (i < tour.size() - 2) {
            output << " - ";
        }
        total_cost += dist[tour[i]][tour[i+1]];
    }

    output << endl << endl;
    output << "La Ruta Óptima tiene un costo total de: " << total_cost << endl << endl;
}

#endif // TSP_H