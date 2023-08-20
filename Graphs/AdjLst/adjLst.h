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
class adjLst
{
private:
    // Using an unordered_map to store the adjacency list
    std::unordered_map<Node, std::vector<Node>> adjacencyList;
    int nodes;

public:
    /**
     * @brief Adds a node to the graph.
     * @param node The node to be added.
     */
    void addNode(const Node &node)
    {
        adjacencyList[node] = std::vector<Node>();
        nodes++;
    }

    /**
     * @brief Adds an edge between two nodes in the graph.
     * @param fromNode The source node.
     * @param toNode The destination node.
     */
    void addEdge(const Node &fromNode, const Node &toNode)
    {
        // Adding the edge to both nodes' adjacency lists
        adjacencyList[fromNode].push_back(toNode);
        adjacencyList[toNode].push_back(fromNode);
    }

    /**
     * @brief Prints the graph's adjacency list.
     */
    void printGraph()
    {

        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it)
        {
            std::cout << "Node " << (it->first).getName() << " is connected to:";
            for (const Node &neighbor : it->second)
            {
                std::cout << " " << neighbor.getName();
            }
            std::cout << std::endl;
        }
    }

    void isConnected(Node start)
    {
        std::unordered_map<Node, bool> visited;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it)
        {
            visited[it->first] = false;
        }

        dfs(start, visited);

        for (auto it = visited.begin(); it != visited.end(); ++it)
        {
            std::cout << std::boolalpha;
            if ((it->first).getName() != start.getName())
            {
                std::cout << (it->first).getName() << " is connected to " << start.getName() << " : " << (it->second) << std::endl;
            }
        }
    }

    void dfs(Node start, std::unordered_map<Node, bool> &visited)
    {
        if (visited[start])
        {
            return;
        }
        else
        {
            visited[start] = true;
            std::vector<Node> neighbors = adjacencyList[start];
            for (const Node &neighbor : neighbors)
            {
                dfs(neighbor, visited);
            }
        }
    }
};

#endif
