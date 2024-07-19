#include "BuildingDirectory.h"
#include "CampusMap.h"
#include "UserDatabase.h"
#include <iostream>
#include <limits>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    BuildingDirectory buildingDirectory;
    CampusMap campusMap;
    UserDatabase userDatabase;

    // Sample Data
    buildingDirectory.addBuilding("Library", 1);
    buildingDirectory.addBuilding("ScienceBlock", 2);
    buildingDirectory.addBuilding("AdminBlock", 3);
    userDatabase.addUser(101, "Alice");
    userDatabase.addUser(102, "Bob");
    campusMap.addEdge(1, 2, 10);
    campusMap.addEdge(2, 3, 20);

    int choice;
    do {
        std::cout << "1. Add Building\n";
        std::cout << "2. Display Buildings\n";
        std::cout << "3. Search Building\n";
        std::cout << "4. Add User\n";
        std::cout << "5. Display Users\n";
        std::cout << "6. Add Path\n";
        std::cout << "7. Display Graph\n";
        std::cout << "8. Find Shortest Path\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        
        while (!(std::cin >> choice) || choice < 1 || choice > 9) {
            std::cout << "Invalid choice. Please enter a number between 1 and 9: ";
            clearInput();
        }

        switch (choice) {
            case 1: {
                std::string name;
                int code;
                std::cout << "Enter Building Name: ";
                std::cin >> name;
                std::cout << "Enter Building Code: ";
                while (!(std::cin >> code)) {
                    std::cout << "Invalid code. Please enter a valid number: ";
                    clearInput();
                }
                buildingDirectory.addBuilding(name, code);
                break;
            }
            case 2:
                buildingDirectory.displayBuildings();
                break;
            case 3: {
                std::string name;
                std::cout << "Enter Building Name: ";
                std::cin >> name;
                Building* building = buildingDirectory.searchBuilding(name);
                if (building) {
                    std::cout << "Building found: " << building->name << " (" << building->code << ")\n";
                } else {
                    std::cout << "Building not found.\n";
                }
                break;
            }
            case 4: {
                int id;
                std::string name;
                std::cout << "Enter User ID: ";
                while (!(std::cin >> id)) {
                    std::cout << "Invalid ID. Please enter a valid number: ";
                    clearInput();
                }
                std::cout << "Enter User Name: ";
                std::cin >> name;
                userDatabase.addUser(id, name);
                break;
            }
            case 5:
                userDatabase.displayUsers();
                break;
            case 6: {
                int src, dest, weight;
                std::cout << "Enter Source Building Code: ";
                while (!(std::cin >> src)) {
                    std::cout << "Invalid code. Please enter a valid number: ";
                    clearInput();
                }
                std::cout << "Enter Destination Building Code: ";
                while (!(std::cin >> dest)) {
                    std::cout << "Invalid code. Please enter a valid number: ";
                    clearInput();
                }
                std::cout << "Enter Path Weight: ";
                while (!(std::cin >> weight)) {
                    std::cout << "Invalid weight. Please enter a valid number: ";
                    clearInput();
                }
                campusMap.addEdge(src, dest, weight);
                break;
            }
            case 7:
                campusMap.displayGraph();
                break;
            case 8: {
                int src, dest;
                std::cout << "Enter Source Building Code: ";
                while (!(std::cin >> src)) {
                    std::cout << "Invalid code. Please enter a valid number: ";
                    clearInput();
                }
                std::cout << "Enter Destination Building Code: ";
                while (!(std::cin >> dest)) {
                    std::cout << "Invalid code. Please enter a valid number: ";
                    clearInput();
                }
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
