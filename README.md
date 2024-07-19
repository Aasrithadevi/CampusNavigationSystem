# CampusNavigationSystem
C++ STL
# Interactive Campus Navigation System

## Description
Welcome to the Interactive Campus Navigation System! This project combines various data structures in C++ to create a user-friendly application that helps navigate a campus. Users can add and manage user information, building data, and campus paths, and find the shortest path between buildings. We've also preloaded some sample data to help you get started quickly.

## Data Structures and Implementation

### 1. User Database (Linked List)
#### Files: `UserDatabase.h`, `UserDatabase.cpp`
- **What It Does**: Manages user information, making it easy to add new users and display the list of users.
- **Key Functions**:
  - `addUser(int id, std::string name)`: Adds a new user to the linked list.
  - `displayUsers() const`: Displays all users in the database.

### 2. Building Directory (Binary Search Tree)
#### Files: `BuildingDirectory.h`, `BuildingDirectory.cpp`
- **What It Does**: Efficiently stores and searches for buildings by name.
- **Key Functions**:
  - `addBuilding(std::string name, int code)`: Adds a new building to the BST.
  - `displayBuildings() const`: Displays all buildings in the directory.
  - `searchBuilding(std::string name) const`: Searches for a building by name and returns its details.

### 3. Campus Map (Graph)
#### Files: `CampusMap.h`, `CampusMap.cpp`
- **What It Does**: Represents the campus map, allowing you to add paths between buildings and find the shortest route between them.
- **Key Functions**:
  - `addEdge(int src, int dest, int weight)`: Adds a path between two buildings with a specified distance.
  - `displayGraph() const`: Displays the entire campus map as an adjacency list.
  - `shortestPath(int src, int dest)`: Finds and displays the shortest path between two buildings using Dijkstra's algorithm.

### 4. Main Program
#### File: `main.cpp`
- **What It Does**: Provides an interactive menu-driven interface for users to interact with the system. It includes functions to add and manage users, buildings, and paths, and to search for buildings or find the shortest path between them.
- **Sample Data**: Preloaded sample data for users, buildings, and paths for demonstration purposes.

## How to Run
1. **Compile and run**:
   ```bash
   g++ main.cpp UserDatabase.cpp BuildingDirectory.cpp CampusMap.cpp -o CampusNavigationSystem
   ./CampusNavigationSystem


