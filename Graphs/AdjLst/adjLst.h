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
        // Create an empty adjacency list entry for the new node
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
        // Iterate through each node and its neighbors, then print the adjacency information
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

    /**
     * @brief Determines whether the graph is connected starting from the given node.
     * @param start The starting node for the connectivity check.
     */
    void isConnected(Node start)
    {
        // Initialize a map to keep track of visited nodes
        std::unordered_map<Node, bool> visited;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it)
        {
            visited[it->first] = false; // Initialize all nodes as unvisited
        }

        // Perform depth-first search (DFS) to mark connected nodes as visited
        dfs(start, visited);

        // Print the connectivity information for each node
        for (auto it = visited.begin(); it != visited.end(); ++it)
        {
            std::cout << std::boolalpha;
            if ((it->first).getName() != start.getName())
            {
                std::cout << (it->first).getName() << " is connected to " << start.getName() << " : " << (it->second) << std::endl;
            }
        }
    }

    /**
     * @brief Performs depth-first search (DFS) from a given node to mark connected nodes.
     * @param start The node to start DFS from.
     * @param visited A map indicating whether each node has been visited.
     */
    void dfs(Node start, std::unordered_map<Node, bool> &visited)
    {
        if (visited[start])
        {
            return; // If node has already been visited, return
        }
        else
        {
            visited[start] = true; // Mark the current node as visited
            std::vector<Node> neighbors = adjacencyList[start]; // Get neighbors of the current node
            for (const Node &neighbor : neighbors)
            {
                dfs(neighbor, visited); // Recursively perform DFS on unvisited neighbors
            }
        }
    }
};

#endif
