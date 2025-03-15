#include <iostream>
#include "../src/graph/graph.hpp"
#include "../src/graph/graph_algorithms.hpp"

int main()
{
    std::cout << "Running Graph Module Tests...\n";

    // Test 1: Graph creation and edge addition.
    Graph graph(5, false);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);

    if (graph.getNumEdges() != 2)
    {
        std::cerr << "Test failed: Expected 2 edges, got " << graph.getNumEdges() << "\n";
        return 1;
    }
    std::cout << "Graph edge addition test passed.\n";

    // Test 2: Depth-First Search (DFS)
    auto dfsResult = depthFirstSearch(graph, 0);
    if (!dfsResult[0] || !dfsResult[1] || !dfsResult[2])
    {
        std::cerr << "Test failed: DFS did not visit expected vertices.\n";
        return 1;
    }
    std::cout << "DFS test passed.\n";

    // Test 3: Breadth-First Search (BFS)
    auto bfsResult = breadthFirstSearch(graph, 0);
    if (!bfsResult[0] || !bfsResult[1] || !bfsResult[2])
    {
        std::cerr << "Test failed: BFS did not visit expected vertices.\n";
        return 1;
    }
    std::cout << "BFS test passed.\n";

    std::cout << "All tests passed successfully.\n";
    return 0;
}
