//
// Created by mementomori on 26.09.2021.
//
#include <iostream>
#include "objects.h"
#include "api.h"

using namespace std;
typedef pair<int, int> coord;
int main() {
    GridGraph g = GridGraph({{"a", {{"b", 3}, {"c", 8}, {"x", 3}}},
                                    {"b", {{"d", 3}}},
                                    {"x", {{"d", 3}}},
                                    {"c", {{"d", 8}}}},
                            {{"a", coord(1, 1)},
                                    {"b", coord(200,200)},
                                    {"c", coord (1, 3)},
                                    {"d", coord(3, 3)},
                                    {"x", coord(3, 1)}});
    unordered_map<string, string> came_from = a_star(g, "a", "d");
    cout << vertexToString(findPath("a", "d", came_from)) << endl;
    return 0;
}
