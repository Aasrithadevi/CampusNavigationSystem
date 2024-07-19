#ifndef CAMPUSMAP_H
#define CAMPUSMAP_H

#include <vector>
#include <unordered_map>

class CampusMap {
public:
    CampusMap();
    void addEdge(int src, int dest, int weight);
    void displayGraph() const;
    void shortestPath(int src, int dest) const;
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjacencyList;
};

#endif // CAMPUSMAP_H
