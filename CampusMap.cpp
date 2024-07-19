#include "CampusMap.h"
#include <iostream>
#include <queue>
#include <limits>

CampusMap::CampusMap() {}

void CampusMap::addEdge(int src, int dest, int weight) {
    adjacencyList[src].push_back({dest, weight});
    adjacencyList[dest].push_back({src, weight});
}

void CampusMap::displayGraph() const {
    for (const auto& node : adjacencyList) {
        std::cout << "Building " << node.first << ": ";
        for (const auto& edge : node.second) {
            std::cout << " -> (" << edge.first << ", " << edge.second << ")";
        }
        std::cout << std::endl;
    }
}

void CampusMap::shortestPath(int src, int dest) const {
    // Implement Dijkstra's algorithm or any other shortest path algorithm
}
