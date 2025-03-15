#include "cli/graph_cli.hpp"

// Main entry point for the application.
// Delegates processing to the graph CLI module.
int main(int argc, char *argv[])
{
    return runGraphCLI(argc, argv);
}
