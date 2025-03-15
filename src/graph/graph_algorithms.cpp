#include "graph_algorithms.hpp"

// Utility function for DFS recursion.
void dfsUtil(const Graph &graph, int vertex, std::vector<bool> &visited)
{
    visited[vertex] = true;
    for (int adjacent : graph.getAdjList()[vertex])
    {
        if (!visited[adjacent])
        {
            dfsUtil(graph, adjacent, visited);
        }
    }
}

std::vector<bool> depthFirstSearch(const Graph &graph, int start)
{
    int n = graph.getNumVertices();
    std::vector<bool> visited(n, false);
    dfsUtil(graph, start, visited);
    return visited;
}

std::vector<bool> breadthFirstSearch(const Graph &graph, int start)
{
    int n = graph.getNumVertices();
    std::vector<bool> visited(n, false);
    std::queue<int> queue;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty())
    {
        int vertex = queue.front();
        queue.pop();
        for (int adjacent : graph.getAdjList()[vertex])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
    return visited;
}
