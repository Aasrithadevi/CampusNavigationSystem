#include "UserDatabase.h"
#include <iostream>

UserDatabase::UserDatabase() : head(nullptr) {}

void UserDatabase::addUser(int id, std::string name) {
    User* newUser = new User(id, name);
    if (!head) {
        head = newUser;
    } else {
        User* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newUser;
    }
}

void UserDatabase::displayUsers() const {
    User* temp = head;
    while (temp) {
        std::cout << temp->id << ": " << temp->name << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}
