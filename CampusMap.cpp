#include "CampusMap.h"
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

Graph::Graph(int vertices) : vertices(vertices) {
    adjList = new std::list<std::pair<int, int>>[vertices];
}

Graph::~Graph() {
    delete[] adjList;
}

void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].emplace_back(dest, weight);
    adjList[dest].emplace_back(src, weight);
}

void Graph::displayGraph() const {
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << ": ";
        for (const auto& dest : adjList[i]) {
            std::cout << "(" << dest.first << ", " << dest.second << ") ";
        }
        std::cout << std::endl;
    }
}

void Graph::shortestPath(int src, int dest) {
    std::vector<int> dist(vertices, INT_MAX);
    std::vector<int> parent(vertices, -1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    pq.push(std::make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        std::cout << "No path from " << src << " to " << dest << std::endl;
        return;
    }

    std::cout << "Shortest path from " << src << " to " << dest << " is " << dist[dest] << std::endl;
    std::cout << "Path: ";
    printPath(parent, dest);
    std::cout << std::endl;
}

void Graph::printPath(const std::vector<int>& parent, int j) const {
    if (parent[j] == -1) {
        std::cout << j << " ";
        return;
    }
    printPath(parent, parent[j]);
    std::cout << j << " ";
}
