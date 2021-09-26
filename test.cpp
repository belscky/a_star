//
// Created by mementomori on 26.09.2021.
//
#include <iostream>
#include "objects.h"

using namespace std;
int main() {
    Graph g;
    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addLink("a", "b", 1);
    g.addLink("b", "c", 2);
    g.addLink("c", "a", 3);
    cout << g.getVertexesList() << endl;
    cout << g.getLinksList() << endl;
    return 0;
}
