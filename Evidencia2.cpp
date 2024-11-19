//Ricardo Hernandez - A00837337
//Last edited: 18/11/24
#include <iostream>
#include <fstream>
#include <sstream>
#include "MST.h"
#include "TSP.h"

using namespace std;

int main() {
    stringstream output;
    vector<Node> nodes, futureNodes;
    vector<vector<int>> dist, paths;
    int n, matrix[nMAX][nMAX] = {0};
    bool matrixBool[nMAX][nMAX] = {0};
    
    readInput(nodes, futureNodes, matrix, matrixBool, dist, paths, n);
    MST(output, matrix, matrixBool, nodes, n);
    TSP(output, nodes, matrix, dist, paths, n);
    centrales(output, nodes, matrix, dist, paths,n);
    nuevas(output, nodes, futureNodes);

    ofstream outfile("checking2.txt");
    outfile << output.str();
    outfile.close();

    return 0;
}

