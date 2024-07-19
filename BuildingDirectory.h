#ifndef BUILDINGDIRECTORY_H
#define BUILDINGDIRECTORY_H

#include <string>

struct Building {
    std::string name;
    int code;
    Building* left;
    Building* right;
    Building(std::string name, int code) : name(name), code(code), left(nullptr), right(nullptr) {}
};

class BuildingDirectory {
public:
    BuildingDirectory();
    void addBuilding(std::string name, int code);
    void displayBuildings() const;
    Building* searchBuilding(std::string name) const;
private:
    Building* root;
    Building* addBuildingHelper(Building* node, std::string name, int code);
    void inorderHelper(Building* node) const;
    Building* searchHelper(Building* node, std::string name) const;
};

#endif // BUILDINGDIRECTORY_H
