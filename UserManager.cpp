#include "UserManager.h"

User* UserManager::findUserById(int userId){
    for (auto& user : users) {
        if (user.getId() == userId) {
            return &user;
        }
    }
    return nullptr;
}

void UserManager::addUser(const User& user) {
    users.push_back(user);
}
void UserManager::printUsers() const {
    for (const auto& u : users) {
        std::cout << u << std::endl;
    }
}