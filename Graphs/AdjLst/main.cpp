#include "adjLst.h"
#include <iostream>

int main(){
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    adjLst graph;
    graph.addNode(a);
    graph.addNode(b);
    graph.addNode(c);
    graph.addNode(d);
    graph.addEdge(a,b);
    graph.addEdge(b,c);
    graph.printGraph();
    graph.isConnected(d);


    return 0;
}