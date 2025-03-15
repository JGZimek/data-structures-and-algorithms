#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <sstream>
#include <queue>
#include <functional>
#include "../graph/graph.hpp"
#include "../graph/graph_algorithms.hpp"

// Prints usage information for the graph CLI.
void printGraphCLIUsage(const std::string &progName)
{
    std::cout << "Usage: " << progName << " --mode {manual, random} --algorithm {dfs, bfs} --start <vertex> [options]\n"
              << "Options:\n"
              << "  --mode {manual, random}     Mode of graph creation. 'manual' asks for input or 'random' generates a random graph.\n"
              << "  --algorithm {dfs, bfs}        Traversal algorithm to use.\n"
              << "  --start <vertex>              Starting vertex for traversal.\n"
              << "  --num-vertices <num>          (random mode) Number of vertices in the graph.\n"
              << "  --num-edges <num>             (random mode) Number of edges to generate.\n"
              << "  --directed                  (optional) Create a directed graph (default is undirected).\n"
              << "  --help, -h                  Show this help message.\n";
}

// Generates a random graph given the number of vertices and edges.
Graph generateRandomGraph(int numVertices, int numEdges, bool directed)
{
    Graph graph(numVertices, directed);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, numVertices - 1);

    for (int i = 0; i < numEdges; i++)
    {
        int src = dist(gen);
        int dest = dist(gen);
        graph.addEdge(src, dest);
    }
    return graph;
}

// Prompts the user to input graph data manually.
Graph createGraphManually(bool directed)
{
    int numVertices, numEdges;
    std::cout << "Enter number of vertices: ";
    std::cin >> numVertices;

    // Create graph instance with given number of vertices.
    Graph graph(numVertices, directed);

    std::cout << "Enter number of edges: ";
    std::cin >> numEdges;

    std::cout << "For each edge, enter the source and destination vertices separated by a space.\n";
    for (int i = 0; i < numEdges; i++)
    {
        int src, dest;
        std::cout << "Edge " << (i + 1) << ": ";
        std::cin >> src >> dest;
        graph.addEdge(src, dest);
    }
    return graph;
}

// Computes DFS traversal order and returns the order as a vector of vertices.
std::vector<int> depthFirstTraversalOrder(const Graph &graph, int start)
{
    int n = graph.getNumVertices();
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    std::function<void(int)> dfs = [&](int vertex)
    {
        visited[vertex] = true;
        order.push_back(vertex);
        for (int adjacent : graph.getAdjList()[vertex])
        {
            if (!visited[adjacent])
            {
                dfs(adjacent);
            }
        }
    };
    dfs(start);
    return order;
}

// Computes BFS traversal order and returns the order as a vector of vertices.
std::vector<int> breadthFirstTraversalOrder(const Graph &graph, int start)
{
    int n = graph.getNumVertices();
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        order.push_back(vertex);
        for (int adjacent : graph.getAdjList()[vertex])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }
    return order;
}

// Main function for graph CLI processing.
int runGraphCLI(int argc, char *argv[])
{
    // Default settings.
    std::string mode = "manual";
    std::string algorithm = "";
    int startVertex = -1;
    int numVertices = 0;
    int numEdges = 0;
    bool directed = false;

    // Parse command-line arguments.
    if (argc < 2)
    {
        printGraphCLIUsage(argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "--help" || arg == "-h")
        {
            printGraphCLIUsage(argv[0]);
            return 0;
        }
        else if (arg == "--mode")
        {
            if (i + 1 < argc)
            {
                mode = argv[++i];
            }
            else
            {
                std::cerr << "Error: --mode requires a value.\n";
                return 1;
            }
        }
        else if (arg == "--algorithm")
        {
            if (i + 1 < argc)
            {
                algorithm = argv[++i];
            }
            else
            {
                std::cerr << "Error: --algorithm requires a value.\n";
                return 1;
            }
        }
        else if (arg == "--start")
        {
            if (i + 1 < argc)
            {
                startVertex = std::stoi(argv[++i]);
            }
            else
            {
                std::cerr << "Error: --start requires a value.\n";
                return 1;
            }
        }
        else if (arg == "--num-vertices")
        {
            if (i + 1 < argc)
            {
                numVertices = std::stoi(argv[++i]);
            }
            else
            {
                std::cerr << "Error: --num-vertices requires a value.\n";
                return 1;
            }
        }
        else if (arg == "--num-edges")
        {
            if (i + 1 < argc)
            {
                numEdges = std::stoi(argv[++i]);
            }
            else
            {
                std::cerr << "Error: --num-edges requires a value.\n";
                return 1;
            }
        }
        else if (arg == "--directed")
        {
            directed = true;
        }
        else
        {
            std::cerr << "Unknown option: " << arg << "\n";
            printGraphCLIUsage(argv[0]);
            return 1;
        }
    }

    // Check required parameters.
    if (algorithm.empty())
    {
        std::cerr << "Error: You must specify an algorithm using --algorithm {dfs, bfs}.\n";
        return 1;
    }
    if (startVertex < 0)
    {
        std::cerr << "Error: You must specify a valid starting vertex using --start.\n";
        return 1;
    }

    // Create the graph.
    Graph graph(0, directed);
    if (mode == "random")
    {
        if (numVertices <= 0 || numEdges < 0)
        {
            std::cerr << "Error: In random mode, you must provide --num-vertices (>0) and --num-edges (>=0).\n";
            return 1;
        }
        graph = generateRandomGraph(numVertices, numEdges, directed);
        std::cout << "Random graph generated with " << numVertices << " vertices and "
                  << numEdges << " edges.\n";
    }
    else if (mode == "manual")
    {
        graph = createGraphManually(directed);
    }
    else
    {
        std::cerr << "Error: Invalid mode. Use 'manual' or 'random'.\n";
        return 1;
    }

    // Check starting vertex validity.
    if (startVertex >= graph.getNumVertices())
    {
        std::cerr << "Error: Starting vertex (" << startVertex << ") is out of range (0 - "
                  << graph.getNumVertices() - 1 << ").\n";
        return 1;
    }

    // Compute and display the traversal order.
    std::vector<int> order;
    if (algorithm == "dfs")
    {
        order = depthFirstTraversalOrder(graph, startVertex);
    }
    else if (algorithm == "bfs")
    {
        order = breadthFirstTraversalOrder(graph, startVertex);
    }
    else
    {
        std::cerr << "Error: Invalid algorithm. Use 'dfs' or 'bfs'.\n";
        return 1;
    }

    std::cout << "\nTraversal (" << algorithm << ") order starting from vertex " << startVertex << ":\n";
    for (int vertex : order)
    {
        std::cout << vertex << " ";
    }
    std::cout << "\n";

    return 0;
}
