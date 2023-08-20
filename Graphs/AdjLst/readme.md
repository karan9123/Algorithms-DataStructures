# Graph Adjacency List Implementation

This repository contains a C++ implementation of an adjacency list data structure for representing graphs. The code provides a `adjLst` class that allows you to create graphs, add nodes and edges, print the adjacency list, and determine connectivity using depth-first search (DFS).

## Contents

- [Overview](#overview)
- [Usage](#usage)
- [How to Compile](#how-to-compile)
- [Credits](#credits)

## Overview

The `adjLst` class represents an adjacency list for a graph, providing methods for common graph operations. The following methods are available:

- `void addNode(const Node &node)`: Adds a node to the graph.
- `void addEdge(const Node &fromNode, const Node &toNode)`: Adds an edge between two nodes.
- `void printGraph()`: Prints the adjacency list of the graph.
- `void isConnected(Node start)`: Determines whether the graph is connected starting from a given node using DFS.

## Usage

1. Include the necessary headers in your C++ program:

```cpp
   #include "adjLst.h"
   #include "node.h" // Include the definition of the Node class
```

2. Create a adjLst object to work with the adjacency list representation of the graph:

```cpp
adjLst graph;
```
3. Add nodes and edges to the graph:

```cpp

Node nodeA("A");
Node nodeB("B");
graph.addNode(nodeA);
graph.addNode(nodeB);
graph.addEdge(nodeA, nodeB);
```

4. Print the adjacency list of the graph:

```cpp
graph.printGraph();
```

5. Determine connectivity using DFS:

```cpp
Node startNode("A");
graph.isConnected(startNode);
```

## How to Compile

1. To compile and run the example program:

2. Make sure you have a C++ compiler installed (e.g., g++).

3. Compile the program:

```sh
g++ -o main main.cpp adjLst.cpp node.cpp
```

4. Run the executable:

```sh
./main
```
## Credits

Comments in this code were generated using ChatGPT, a language model developed by OpenAI. The model was used to provide explanations and descriptions for the code. For more information about ChatGPT, visit the [OpenAI website](https://openai.com/).



Make sure to replace `main.cpp`, `adjLst.cpp`, and `node.cpp` with the actual filenames if they are different in your project. This `README.md` file provides an overview of the code, how to use it, how to compile it, and credits the use of ChatGPT for generating comments and explanations.