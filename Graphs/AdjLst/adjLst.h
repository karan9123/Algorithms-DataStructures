#ifndef ADJLST_H
#define ADJLST_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include "node.h"

/**
 * @class adjLst
 * @brief Represents an adjacency list for a graph.
 */
class adjLst {
private:
    // Using an unordered_map to store the adjacency list
    std::unordered_map<Node, std::vector<Node>> adjacencyList;

public:
    /**
     * @brief Adds a node to the graph.
     * @param node The node to be added.
     */
    void addNode(const Node& node) {
        adjacencyList[node] = std::vector<Node>();
    }

    /**
     * @brief Adds an edge between two nodes in the graph.
     * @param fromNode The source node.
     * @param toNode The destination node.
     */
    void addEdge(const Node& fromNode, const Node& toNode) {
        // Adding the edge to both nodes' adjacency lists
        adjacencyList[fromNode].push_back(toNode);
        adjacencyList[toNode].push_back(fromNode);
    }

    /**
     * @brief Prints the graph's adjacency list.
     */
    void printGraph() {

        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
            std::cout << "Node " << (it->first).getName() << " is connected to:";
            for (const Node& neighbor : it->second) {
                std::cout << " " << neighbor.getName();
            }
            std::cout << std::endl;
        }
    }

    
};

#endif
