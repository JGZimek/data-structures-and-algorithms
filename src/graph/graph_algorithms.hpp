#ifndef GRAPH_ALGORITHMS_HPP
#define GRAPH_ALGORITHMS_HPP

#include "graph.hpp"
#include <vector>
#include <queue>

// Performs Depth-First Search (DFS) starting from the given vertex.
// Returns a vector<bool> indicating which vertices were visited.
std::vector<bool> depthFirstSearch(const Graph &graph, int start);

// Performs Breadth-First Search (BFS) starting from the given vertex.
// Returns a vector<bool> indicating which vertices were visited.
std::vector<bool> breadthFirstSearch(const Graph &graph, int start);

#endif // GRAPH_ALGORITHMS_HPP
