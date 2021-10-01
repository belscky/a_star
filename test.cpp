//
// Created by mementomori on 26.09.2021.
//
#include <iostream>
#include "objects.h"
#include "api.h"

using namespace std;
typedef pair<int, int> coord;
int main() {
    GridGraph g1 = GridGraph({{"a", {{"b", 3}, {"c", 8}, {"x", 3}}},
                                    {"b", {{"d", 3}}},
                                    {"x", {{"d", 3}}},
                                    {"c", {{"d", 8}}}},
                            {{"a", coord(0, 0)},
                                    {"b", coord(200,200)},
                                    {"c", coord (1, 3)},
                                    {"d", coord(3, 3)},
                                    {"x", coord(3, 1)}});

    GridGraph g2 = GridGraph({{"a", {{"b", 2}, {"c", 2}, {"d", 1}}},
                              {"b", {{"x", 1}}},
                              {"c", {{"x", 1}}},
                              {"d", {{"x", 2}}},
                              {"x", {{"y", 1}}}},
                             {{"a", coord(0, 0)},
                              {"b", coord(0,3)},
                              {"c", coord (1, 0)},
                              {"d", coord(2, 2)},
                              {"x", coord(5, 5)},
                              {"y", coord(7,8)}});

    auto came_from1 = a_star(g1, "a", "d");
    auto came_from2 = a_star(g2, "a", "y");
    cout << vertexToString(findPath("a", "d", came_from1)) << endl;
    cout << vertexToString(findPath("a", "y", came_from2)) << endl;
    return 0;
}
