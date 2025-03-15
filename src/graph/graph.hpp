#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>

// Graph class represents an unweighted graph using an adjacency list.
// It can be directed or undirected.
class Graph
{
public:
    // Constructor: initializes a graph with the given number of vertices.
    // If directed is false, the graph is undirected.
    Graph(int vertices, bool directed = false);

    // Adds an edge from source to destination.
    // In an undirected graph, an edge is added both ways.
    void addEdge(int source, int destination);

    // Returns the number of vertices in the graph.
    int getNumVertices() const;

    // Returns the number of edges in the graph.
    int getNumEdges() const;

    // Provides constant access to the adjacency list.
    const std::vector<std::list<int>> &getAdjList() const;

private:
    int vertices;                        // Number of vertices
    int edges;                           // Number of edges
    bool directed;                       // True if graph is directed
    std::vector<std::list<int>> adjList; // Adjacency list representation
};

#endif // GRAPH_HPP
