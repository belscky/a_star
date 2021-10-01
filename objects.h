//
// Created by mementomori on 26.09.2021.
//
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>
#ifndef A_STAR_OBJECTS_H
#define A_STAR_OBJECTS_H
using namespace std;

struct GridGraph {
    unordered_map<string, unordered_map<string, int>> edges;
    unordered_map<string, pair<int, int>> coords;
    int n, m;
    GridGraph(unordered_map<string, unordered_map<string, int>> _edges, int _n, int _m, unordered_map<string, pair<int, int>> _coords) {
        edges = _edges;
        n = _n;
        m = _m;
        coords = _coords;
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

    pair<int, int> vertexCoordinates(string vertex) {
        return coords[vertex];
    }

    int h_grid(string x, string y) {
        return abs(vertexCoordinates(x).first - vertexCoordinates(y).first) + abs(vertexCoordinates(x).second - vertexCoordinates(y).second);
    }
};

template<typename T, typename priority_t>
struct PriorityQueue {
    typedef pair<priority_t, T> element;
    priority_queue<element, vector<element>, greater<element>> elements;

    bool empty() {
        return elements.empty();
    }

    void put(T item, priority_t priority) {
        elements.emplace(priority, item);
    }

    T get() {
        T item = elements.top().second;
        elements.pop();
        return item;
    }
};

#endif //A_STAR_OBJECTS_H
