#include <iostream>
#include <vector>
#include <algorithm>
#include "User.h"
class UserManager {
private:
    std::vector<User> users;
public:
    void addUser(const User& user); 
    void printUsers() const;
};