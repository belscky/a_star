//
// Created by mementomori on 29.09.2021.
//
#include <vector>
#include <queue>
#include <unordered_set>
#include "objects.h"
#include <string>
#ifndef A_STAR_API_H
#define A_STAR_API_H

vector<string> bfs(Graph g, string start) {
    queue<string> frontier;
    frontier.push(start);
    vector<string> path;

    unordered_set<string> reached;
    reached.insert(start);

    while (!frontier.empty()) {
        string current = frontier.front();
        frontier.pop();

        path.push_back(current);

        for (string next : g.neighbors(current)) {
            if (reached.find(next) == reached.end()) {
                frontier.push(next);
                reached.insert(next);
            }
        }
    }
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
