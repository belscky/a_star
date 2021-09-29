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

vector<string> dijkstra(Graph g, string start, string end) {
    // не дописан блять !!!
    queue<string> frontier;
    unordered_map<string, string> came_from;
    unordered_map<string, double> edges_cost;
    vector<string> path;
    unordered_set<string> reached;
    frontier.push(start);
    reached.insert(start);

    came_from[start] = start;
    edges_cost[start] = 0;

    while (!frontier.empty()) {
        string current = frontier.front();
        frontier.pop();

        if (current == end) {
            break;
        }

        for (string next : g.neighbors(current)) {
            double new_cost = edges_cost[current] + g.cost(current, next);
            if (edges_cost.find(next) == edges_cost.end() || new_cost < edges_cost[next]) {
                edges_cost[next] = new_cost;
                came_from[next] = current;
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
