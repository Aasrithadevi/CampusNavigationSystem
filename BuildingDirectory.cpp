#include "BuildingDirectory.h"
#include <iostream>

BuildingDirectory::BuildingDirectory() : root(nullptr) {}

void BuildingDirectory::addBuilding(std::string name, int code) {
    root = addBuildingHelper(root, name, code);
}

void BuildingDirectory::displayBuildings() const {
    inorderHelper(root);
    std::cout << std::endl;
}

Building* BuildingDirectory::searchBuilding(std::string name) const {
    return searchHelper(root, name);
}

Building* BuildingDirectory::addBuildingHelper(Building* node, std::string name, int code) {
    if (!node) return new Building(name, code);
    if (name < node->name)
        node->left = addBuildingHelper(node->left, name, code);
    else
        node->right = addBuildingHelper(node->right, name, code);
    return node;
}

void BuildingDirectory::inorderHelper(Building* node) const {
    if (node) {
        inorderHelper(node->left);
        std::cout << node->name << " (" << node->code << ") ";
        inorderHelper(node->right);
    }
}

Building* BuildingDirectory::searchHelper(Building* node, std::string name) const {
    if (!node || node->name == name) return node;
    if (name < node->name) return searchHelper(node->left, name);
    return searchHelper(node->right, name);
}
