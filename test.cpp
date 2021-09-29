//
// Created by mementomori on 26.09.2021.
//
#include <iostream>
#include "objects.h"
#include "api.h"

using namespace std;
int main() {
    Graph g = Graph({{"a", {"b", "c"}},
                            {"b", {"a", "c"}},
                            {"c", {"a", "b"}}});
    cout << vertexToString(g.neighbors("b")) << endl;
    return 0;
}
