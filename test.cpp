//
// Created by mementomori on 26.09.2021.
//
#include <iostream>
#include "objects.h"
#include "api.h"

using namespace std;
int main() {
    Graph g = Graph({{"a", {{"b", 4.5}, {"c", 3.6}}},
                             {"b", {{"d", 3.6}}}});
    cout << g.cost("a", "b") << endl;
    return 0;
}
