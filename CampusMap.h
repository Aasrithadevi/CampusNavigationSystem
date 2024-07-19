#ifndef CAMPUSMAP_H
#define CAMPUSMAP_H

#include <list>
#include <vector>

class Graph {
public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int src, int dest, int weight);
    void displayGraph() const;
    void shortestPath(int src, int dest);
private:
    int vertices;
    std::list<std::pair<int, int>>* adjList;
    void printPath(const std::vector<int>& parent, int j) const;
};

#endif // CAMPUSMAP_H
