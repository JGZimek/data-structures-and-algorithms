#include "graph.hpp"

Graph::Graph(int vertices, bool directed)
    : vertices(vertices), edges(0), directed(directed), adjList(vertices) {}

void Graph::addEdge(int source, int destination)
{
    if (source >= 0 && source < vertices && destination >= 0 && destination < vertices)
    {
        adjList[source].push_back(destination);
        if (!directed)
        {
            adjList[destination].push_back(source);
        }
        ++edges;
    }
}

int Graph::getNumVertices() const
{
    return vertices;
}

int Graph::getNumEdges() const
{
    return edges;
}

const std::vector<std::list<int>> &Graph::getAdjList() const
{
    return adjList;
}