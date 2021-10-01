//
// Created by mementomori on 29.09.2021.
//
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include "objects.h"
#include <string>
#ifndef A_STAR_API_H
#define A_STAR_API_H

unordered_map<string, string> a_star(GridGraph graph, string start, string end) {
    queue<string> visited;
    PriorityQueue<string, int> to_visit;
    to_visit.put(start, 0);
    unordered_map<string, int> g, f;
    unordered_map<string, string> came_from;
    came_from[start] = start;
    g[start] = 0;
    f[start] = 0;
    while (!to_visit.empty()) {
        string current = to_visit.get();
        if (current == end) {
            break;
        }
        visited.push(current);
        for (string next : graph.neighbors(current)) {
            int tentativeScore = g[current] + graph.cost(current, next);
            if (g.find(next) == g.end() || tentativeScore < g[next]) {
                g[next] = tentativeScore;
                f[next] = g[next] + graph.h_grid(current, next);
                came_from[next] = current;
                to_visit.put(next, tentativeScore);
            }
        }
    }
    return came_from;
}

vector<string> findPath(string start, string end, unordered_map<string, string> came_from) {
    vector<string> path;
    string current = end;
    while (current != start) {
        path.push_back(current);
        current = came_from[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

string vertexToString(vector<string> v) {
    string result = "";
    for (int i=0; i<v.size(); i++) {
        result += v[i] + " ";
    }
    return result;
}

#endif //A_STAR_API_H
