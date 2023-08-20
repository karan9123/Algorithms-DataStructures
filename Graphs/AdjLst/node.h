#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <functional>

/**
 * @class Node
 * @brief Represents a node in a graph.
 */
class Node {
private:
    std::string nodeName; // Private member to store the node's name

public:
    /**
     * @brief Constructor to initialize the node with a name.
     * @param name The name of the node.
     */
    Node(const std::string& name) : nodeName(name) {}

    /**
     * @brief Gets the name of the node.
     * @return The name of the node.
     */
    std::string getName() const {
        return nodeName;
    }

    /**
     * @brief Overload of the equality operator for comparing nodes.
     * @param other The other Node to compare with.
     * @return true if the nodes are equal, false otherwise.
     */
    bool operator==(const Node& other) const {
        return nodeName == other.nodeName;
    }
};

namespace std {
    /**
     * @brief Specialization of std::hash for the Node class.
     */
    template <>
    struct hash<Node> {
        /**
         * @brief Computes the hash value for a Node.
         * @param node The Node to compute the hash for.
         * @return The hash value.
         */
        size_t operator()(const Node& node) const {
            return std::hash<std::string>()(node.getName());
        }
    };
}

#endif
