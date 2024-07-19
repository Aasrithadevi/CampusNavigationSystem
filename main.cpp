#include <iostream>
#include "UserDatabase.h"
#include "BuildingDirectory.h"
#include "CampusMap.h"

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add User\n";
    std::cout << "2. Display Users\n";
    std::cout << "3. Add Building\n";
    std::cout << "4. Display Buildings\n";
    std::cout << "5. Search Building\n";
    std::cout << "6. Add Path between Buildings\n";
    std::cout << "7. Display Campus Map\n";
    std::cout << "8. Find Shortest Path\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

void addSampleData(UserDatabase& users, BuildingDirectory& directory, Graph& campusMap) {
    // Adding sample users
    users.addUser(1, "Alice");
    users.addUser(2, "Bob");
    users.addUser(3, "Charlie");

    // Adding sample buildings
    directory.addBuilding("Library", 101);
    directory.addBuilding("Admin", 102);
    directory.addBuilding("Cafeteria", 103);
    directory.addBuilding("Gym", 104);
    directory.addBuilding("Lab", 105);

    // Adding sample paths
    campusMap.addEdge(101, 102, 10);
    campusMap.addEdge(101, 103, 20);
    campusMap.addEdge(102, 103, 5);
    campusMap.addEdge(103, 104, 15);
    campusMap.addEdge(104, 105, 10);
    campusMap.addEdge(101, 105, 25);
}

int main() {
    UserDatabase users;
    BuildingDirectory directory;
    Graph campusMap(200); // Assume codes range from 100 to 199

    addSampleData(users, directory, campusMap);

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            std::string name;
            std::cout << "Enter User ID: ";
            std::cin >> id;
            std::cout << "Enter User Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            users.addUser(id, name);
            break;
        }
        case 2:
            users.displayUsers();
            break;
        case 3: {
            std::string name;
            int code;
            std::cout << "Enter Building Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter Building Code: ";
            std::cin >> code;
            directory.addBuilding(name, code);
            break;
        }
        case 4:
            directory.displayBuildings();
            break;
        case 5: {
            std::string name;
            std::cout << "Enter Building Name to Search: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            Building* building = directory.searchBuilding(name);
            if (building) {
                std::cout << "Building Found: " << building->name << " (" << building->code << ")" << std::endl;
            } else {
                std::cout << "Building Not Found" << std::endl;
            }
            break;
        }
        case 6: {
            int src, dest, weight;
            std::cout << "Enter Source Building Code: ";
            std::cin >> src;
            std::cout << "Enter Destination Building Code: ";
            std::cin >> dest;
            std::cout << "Enter Path Weight: ";
            std::cin >> weight;
            campusMap.addEdge(src, dest, weight);
            break;
        }
        case 7:
            campusMap.displayGraph();
            break;
        case 8: {
            int src, dest;
            std::cout << "Enter Source Building Code: ";
            std::cin >> src;
            std::cout << "Enter Destination Building Code: ";
            std::cin >> dest;
            campusMap.shortestPath(src, dest);
            break;
        }
        case 9:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 9);

    return 0;
}
