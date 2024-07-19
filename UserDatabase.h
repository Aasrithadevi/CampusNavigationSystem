#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <string>

struct User {
    int id;
    std::string name;
    User* next;
    User(int id, std::string name) : id(id), name(name), next(nullptr) {}
};

class UserDatabase {
public:
    UserDatabase();
    void addUser(int id, std::string name);
    void displayUsers() const;
private:
    User* head;
};

#endif // USERDATABASE_H
