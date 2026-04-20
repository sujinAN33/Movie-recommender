#include "UserManager.h"
void UserManager::addUser(const User& user) {
    users.push_back(user);
}
void UserManager::printUsers() const {
    for (const auto& u : users) {
        std::cout << u << std::endl;
    }
}