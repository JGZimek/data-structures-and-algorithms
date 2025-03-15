# Data Structures and Algorithms

## Overview

This project is a professional implementation of various data structures and algorithms in C++. Currently, the focus is on a graph data structure along with implementations of Depth-First Search (DFS) and Breadth-First Search (BFS) algorithms. A command-line interface (CLI) is provided for generating graphs, testing traversal algorithms, and experimenting with various configurations. The project is designed in a modular fashion to easily incorporate additional data structures and algorithms in the future.

## Project Structure

- **/src/graph**: Contains the implementation of the Graph class and related graph algorithms.
  - `graph.hpp` and `graph.cpp`: Implementation of the graph data structure using an adjacency list.
  - `graph_algorithms.hpp` and `graph_algorithms.cpp`: Implementation of DFS and BFS algorithms.
- **/src/cli**: Contains CLI modules (e.g. `graph_cli.hpp` and `graph_cli.cpp`) for graph operations.
- **/src**: Contains the main entry point of the application (`main.cpp`) which delegates CLI processing to the appropriate module.
- **/tests**: Unit tests for the graph and its algorithms.
- **CMakeLists.txt**: Build configuration for the project.
- **README.md**: Project documentation.

## Getting Started

Follow these steps to build and run the project:

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/JGZimek/data-structures-and-algorithms.git
   cd data-structures-and-algorithms
   ```

2. **Build the Project**:

   Using CMake:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. **Run the Application**:

   From the build directory:
   ```bash
   ./bin/cli_app [options]
   ```

## Usage

The CLI provides various options for generating and traversing graphs. You can choose between a manual mode (interactive input) or a random mode (auto-generated graph), select the traversal algorithm (DFS or BFS), specify the starting vertex, and set whether the graph is directed.

### Command-line Interface

#### Random Graph with DFS

Generate a random graph with 10 vertices and 15 edges and perform DFS starting from vertex 0:
```bash
./bin/cli_app --mode random --num-vertices 10 --num-edges 15 --algorithm dfs --start 0
```

#### Manual Graph with BFS

Interactively create a graph and perform BFS starting from vertex 2:
```bash
./bin/cli_app --mode manual --algorithm bfs --start 2
```

During manual mode, you will be prompted for:
- The number of vertices.
- The number of edges.
- For each edge, you will be prompted with "Edge X:" where you need to enter the source and destination vertices separated by a space.

### Available Options

- `--mode {manual, random}`: Mode of graph creation. Use `manual` for interactive input or `random` for auto-generated graphs.
- `--algorithm {dfs, bfs}`: Select the graph traversal algorithm.
- `--start <vertex>`: Specify the starting vertex for traversal.
- `--num-vertices <num>`: (random mode) Set the number of vertices in the graph.
- `--num-edges <num>`: (random mode) Set the number of edges to generate.
- `--directed`: (optional) Create a directed graph (default is undirected).
- `--help, -h`: Display the help message.

## Documentation

### Graph Module

- **Graph Class**: Implements an unweighted graph using an adjacency list.
  - `addEdge(source, destination)`: Adds an edge between two vertices. For undirected graphs, the edge is added both ways.
  - `getNumVertices()`, `getNumEdges()`: Return the number of vertices and edges, respectively.
  - `getAdjList()`: Provides read-only access to the graph's internal adjacency list.

### Graph Algorithms

- **Depth-First Search (DFS)**:
  - `depthFirstSearch(graph, start)`: Performs DFS traversal from a specified starting vertex.
- **Breadth-First Search (BFS)**:
  - `breadthFirstSearch(graph, start)`: Performs BFS traversal from a specified starting vertex.

## Testing

Unit tests are provided in the `/tests` directory. To run the tests, from the build directory use:

```bash
ctest
```

For more detailed output, you can run:

```bash
ctest --verbose
```

## Future Extensions

- **Additional Data Structures**: New modules can be added under `/src` (e.g., trees, stacks, queues) to expand the project.
- **New Algorithms**: Additional algorithms can be implemented in a modular manner.
- **Enhanced CLI**: The CLI is designed to be extensible with more options and subcommands as new features are integrated.

## Contact

For any inquiries, please contact [jgzimek@gmail.com].
