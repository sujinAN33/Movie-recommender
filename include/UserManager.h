#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "User.h"
#include "BaseManager.h"
class UserManager : public BaseManager {
private:
    std::vector<User> users;
public:
    std::vector<User> getUsers() const { return users; } // users 벡터에 접근할 수 있는 getter 추가
    User* findUserById(int userId);
    void addUser(const User& user); 
    void printUsers() const;
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
    int size() const;
};

bool operator==(const User& lhs, const User& rhs);
bool operator!=(const User& lhs, const User& rhs);
bool operator<(const User& lhs, const User& rhs);
bool operator>(const User& lhs, const User& rhs);
bool operator<=(const User& lhs, const User& rhs);
bool operator>=(const User& lhs, const User& rhs);
std::ostream& operator<<(std::ostream& os, const User& user);