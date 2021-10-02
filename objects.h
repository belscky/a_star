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
    // struct of graph with vertexes on infinite grid
    unordered_map<string, unordered_map<string, double>> edges;
    unordered_map<string, pair<double, double>> coords;
    GridGraph(unordered_map<string, unordered_map<string, double>> _edges, unordered_map<string, pair<double, double>> _coords) {
        /* _edges: dictionary with dictionaries with names of vertexes and weights of edges between vertexes
         * _coords: dictionary {a: pair(x, y)} with vertex coordinates on grid */
        edges = _edges;
        coords = _coords;
    }

    vector<string> neighbors(string vertex) {
        // Returns vector of vertex neighbors
        vector<string> result;
        auto it = edges[vertex].begin();
        for (int i=0; it != edges[vertex].end(); it++, i++) {
            result.push_back(it->first);
        }
        return result;
    }

    double cost(string x, string y) {
        // Returns cost of moving from x to y
        return edges[x][y];
    }

    double h_grid(string x, string y) {
        // Returns heuristic function (Euclid distance)
        double x_c = pow(coords[x].first - coords[y].first, 2);
        double y_c = pow(coords[x].second - coords[y].second, 2);
        return sqrt(x_c + y_c);
    }
};

template<typename T, typename priority_t>
struct PriorityQueue {
    /* wrapper of priority_queue class to manipulate with pairs */
    typedef pair<priority_t, T> element;
    priority_queue<element, vector<element>, greater<element>> elements;

    bool empty() {
        // if queue is empty
        return elements.empty();
    }

    void put(T item, priority_t priority) {
        // add element to queue
        elements.emplace(priority, item);
    }

    T get() {
        // get an element and pop it from queue
        T item = elements.top().second;
        elements.pop();
        return item;
    }
};

#endif //A_STAR_OBJECTS_H
