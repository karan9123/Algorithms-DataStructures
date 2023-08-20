#include "adjLst.h"
#include <iostream>

int main(){
    Node a("a");
    Node b("b");
    Node c("c");
    adjLst graph;
    graph.addNode(a);
    graph.addNode(b);
    graph.addNode(c);
    graph.addEdge(a,b);
    graph.addEdge(b,c);
    graph.printGraph();
    return 0;
}