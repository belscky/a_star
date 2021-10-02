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
    /* a_star algorithm on GridGraph
     *
     * graph: graph object
     * start: start vertex name
     * end: end vertex name
     *
     * return: dictionary where pair (key, value) is meaning (vertex, parent vertex)*/
    unordered_map<string, string> none = {{"none", "none"}};
    queue<string> visited;
    PriorityQueue<string, double> to_visit;
    to_visit.put(start, 0);
    unordered_map<string, double> g, f;
    bool flag = true;
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
            double tentativeScore = g[current] + graph.cost(current, next);
            if (g.find(next) == g.end() || tentativeScore < g[next]) {
                g[next] = tentativeScore;
                f[next] = g[next] + graph.h_grid(current, next);
                came_from[next] = current;
                to_visit.put(next, f[next]);
            }
        }
    }
    if (came_from.find(end) != came_from.end())
        return came_from;
    else
        return none;
}

vector<string> findPath(string start, string end, unordered_map<string, string> came_from) {
    /* finds path from returned dict from a_star
     *
     * start: start vertex name
     * end: end vertex name
     * came_from: returned from a_star
     *
     * return: vector of vertexes of path from start to end*/
    vector<string> path;
    vector<string> none;
    none.emplace_back("none");
    string current = end;
    while (current != start) {
        path.push_back(current);
        if (came_from.find(current) == came_from.end())
            return none;
        else
            current = came_from[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

string vertexToString(vector<string> v) {
    // Converts vertex to string
    string result;
    for (auto & i : v) {
        result += i + " ";
    }
    return result;
}

#endif //A_STAR_API_H
