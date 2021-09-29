//
// Created by mementomori on 26.09.2021.
//
#include <string>
#include <vector>
#include <unordered_map>
#ifndef A_STAR_OBJECTS_H
#define A_STAR_OBJECTS_H
using namespace std;

struct Graph {
    unordered_map<string, vector<string>> edges;
    unordered_map<string, unordered_map<string, double>> weights;
    Graph(unordered_map<string, vector<string>> _edges, unordered_map<string, unordered_map<string, double>> _weights) {
        edges = _edges;
        weights = _weights;
    }

    vector<string> neighbors(string vertex) {
        return edges[vertex];
    }

    double cost(string x, string y) {
        return weights[x][y];
    }
};

#endif //A_STAR_OBJECTS_H
