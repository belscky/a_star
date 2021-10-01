//
// Created by mementomori on 26.09.2021.
//
#include <iostream>
#include "objects.h"
#include "api.h"

using namespace std;
typedef pair<int, int> coord;
int main() {
    GridGraph g = GridGraph({{"a", {{"b", 3}, {"c", 4}}},
                                    {"b", {{"d", 3}}},
                                    {"c", {{"d", 4}}}}, 10, 10,
                            {{"a", coord(1, 1)},
                                    {"b", coord(20,1)},
                                    {"c", coord (1, 3)},
                                    {"d", coord(3, 3)}});
    cout << vertexToString(findPath("a", "d", a_star(g, "a", "d"))) << endl;
    return 0;
}
