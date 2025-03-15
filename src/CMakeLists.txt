# This file configures the build for the source files.

# Create the main application executable.
# The main entry point is in src/main.cpp, which delegates CLI processing to the appropriate modules.
add_executable(cli_app 
    main.cpp
    cli/graph_cli.cpp
    graph/graph.cpp
    graph/graph_algorithms.cpp
)

# Specify the include directories for headers from the cli and graph modules.
target_include_directories(cli_app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/cli
    ${CMAKE_CURRENT_SOURCE_DIR}/graph
)
