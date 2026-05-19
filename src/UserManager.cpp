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
// BaseManager의 순수 가상 함수 구현
void UserManager::loadFromFile(const std::string& filename) override {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
        return;
    }
    std::string line;
    getline(file, line); // 헤더 스킵
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        getline(ss, token, '|'); int id= stoi(token);
        getline(ss, token, '|'); std::string name = token;
        getline(ss, token, '|'); std::string email = token;   
        users.push_back(User(id, name, email));
    }
    file.close();
}
void UserManager::saveToFile(const std::string& filename) const override {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
        return;
    }
    file << "id|name|email\n"; // 헤더 작성
    for (const auto& user : users) {
        file << user.getId() << "|"
             << user.getName() << "|"
             << user.getEmail() << "\n";
    }
    file.close();
}
int UserManager::size() const override{
    return users.size();
}

//비교 연산자 오버로드
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