cmake_minimum_required(VERSION 3.8)
project(shortest_path)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/Graph.cpp include/Graph.h src/AdjacencyList.cpp include/AdjacencyList.h src/Node.cpp include/Node.h src/MinimumHeap.cpp include/MinimumHeap.h src/HeapNode.cpp include/HeapNode.h src/Dijkstra.cpp include/Dijkstra.h)
add_executable(shortest_path ${SOURCE_FILES})