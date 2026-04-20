#include "User.h"
#include <iostream>
using namespace std;

User::User() : id(0) {}  // 기본 생성자
User::User(int id, const string& name, const string& email)
    : id(id), name(name), email(email) {} //초기화 리스트

int User::getId() const { return id; }
string User::getName() const { return name; }
string User::getEmail() const { return email; }


//연산자 오버로딩
bool User::operator==(const User& other) const {
    return id == other.id && name == other.name && email == other.email;
}
bool User::operator!=(const User& other) const {
    return !(*this == other);
}
bool User::operator<(const User& other) const {
    return id < other.id;
}
bool User::operator>(const User& other) const {
    return id > other.id;
}
bool User::operator<=(const User& other) const {
    return id <= other.id;
}
bool User::operator>=(const User& other) const {
    return id >= other.id;
}
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "아이디: " << user.id << ", 이름: " << user.name << ", 이메일: " << user.email;
    return os;
}