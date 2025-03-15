# Create the test executable using test_graph.cpp.
add_executable(test_graph 
    test_graph.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/graph.cpp
    ${CMAKE_SOURCE_DIR}/src/graph/graph_algorithms.cpp
)

# Include the graph headers for testing.
target_include_directories(test_graph PRIVATE ${CMAKE_SOURCE_DIR}/src/graph)

# Register the test with CTest.
add_test(NAME GraphTests COMMAND test_graph)
