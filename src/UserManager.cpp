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

bool operator==(const User& lhs, const User& rhs) {
    return lhs.getId() == rhs.getId() &&
           lhs.getName() == rhs.getName() &&
           lhs.getEmail() == rhs.getEmail();
}

bool operator!=(const User& lhs, const User& rhs) {
    return !(lhs == rhs);
}

bool operator<(const User& lhs, const User& rhs) {
    return lhs.getId() < rhs.getId();
}

bool operator>(const User& lhs, const User& rhs) {
    return lhs.getId() > rhs.getId();
}

bool operator<=(const User& lhs, const User& rhs) {
    return lhs.getId() <= rhs.getId();
}

bool operator>=(const User& lhs, const User& rhs) {
    return lhs.getId() >= rhs.getId();
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "아이디: " << user.getId()
       << ", 이름: " << user.getName()
       << ", 이메일: " << user.getEmail();
    return os;
}