#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "User.h"
class UserManager {
private:
    std::vector<User> users;
public:
    std::vector<User> getUsers() const { return users; } // users 벡터에 접근할 수 있는 getter 추가
    User* findUserById(int userId);
    void addUser(const User& user); 
    void printUsers() const;
};