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
    unordered_map<string, unordered_map<string, double>> edges;
    Graph(unordered_map<string, unordered_map<string, double>> _edges) {
        edges = _edges;
    }

    vector<string> neighbors(string vertex) {
        vector<string> result;
        auto it = edges[vertex].begin();
        for (int i=0; it != edges[vertex].end(); it++, i++) {
            result.push_back(it->first);
        }
        return result;
    }

    double cost(string x, string y) {
        return edges[x][y];
    }
};

#endif //A_STAR_OBJECTS_H
