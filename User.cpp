#include "User.h"
#include <iostream>
using namespace std;

User::User() : id(0) {}  // 기본 생성자
User::User(int id, const string& name, const string& email)
    : id(id), name(name), email(email) {} //초기화 리스트

int User::getId() const { return id; }
string User::getName() const { return name; }
string User::getEmail() const { return email; }
void User::display() const {
    cout << "아이디 : "<<id <<",이름 : "<<name<<",이메일 : "<<email<<endl;
}
