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
    Graph(unordered_map<string, vector<string>> _edges) {
        edges = _edges;
    }
    vector<string> neighbors(string vertex) {
        return edges[vertex];
    }
};

#endif //A_STAR_OBJECTS_H
