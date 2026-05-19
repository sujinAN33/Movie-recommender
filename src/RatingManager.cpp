#include "RatingManager.h"
using namespace std;

bool RatingManager::addRating(Movie& movie, Rating& rating){

    for (const auto& existing : ratings) {
        if (existing.getUserId() == rating.getUserId() &&
            existing.getMovieId() == rating.getMovieId()) {
            std::cerr << "이미 평점을 입력한 영화입니다." << std::endl;
            return false;
        }
    }

    ratings.push_back(rating);
    movie.addRating(rating.getScore());
    return true;
}

void RatingManager::displayRatings(int movieId) const {
    bool found = false;
    for (const auto& rating : ratings) {
        if (rating.getMovieId() == movieId) {
            std::cout << rating << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "해당 영화에 대한 평점이 없습니다." << std::endl;
    }
}

std::vector<Rating> RatingManager::findByUser(int userId) const {
    std::vector<Rating> userRatings;
    for (const auto& rating : ratings) {
        if (rating.getUserId() == userId) {
            userRatings.push_back(rating);
        }
    }
    return userRatings;
}
std::vector<int> RatingManager::getAllUserIds() const {
    std::vector<int> userIds;
    for (const auto& rating : ratings) {
        if (std::find(userIds.begin(), userIds.end(), rating.getUserId()) == userIds.end()) {
            userIds.push_back(rating.getUserId());
        }
    }
    return userIds;
}

// BaseManager의 순수 가상 함수 구현
void RatingManager::loadFromFile(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
        return;
    }  
    string line;
    getline(file, line); // 헤더 스킵
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, '|'); int userId= stoi(token);
        getline(ss, token, '|'); int movieId= stoi(token);
        getline(ss, token, '|'); double rating=stod(token);

        ratings.push_back(Rating(userId, movieId, rating));
    }
    file.close();
}
void RatingManager::saveToFile(const std::string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
        return;
    }
    file << "userId|movieId|rating\n"; // 헤더 작성
    for (const auto& rating : ratings) {
        file << rating.getUserId() << "|"
             << rating.getMovieId() << "|"
             << rating.getScore() << "\n";
    }
    file.close();
}
int RatingManager::size() const {
    return ratings.size();
}

// 비교 연산자 오버로드
bool operator==(const Rating& lhs, const Rating& rhs) {
    return lhs.getUserId() == rhs.getUserId() &&
           lhs.getMovieId() == rhs.getMovieId() &&
           lhs.getScore() == rhs.getScore();
}

bool operator!=(const Rating& lhs, const Rating& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Rating& lhs, const Rating& rhs) {
    return lhs.getScore() < rhs.getScore();
}

bool operator>(const Rating& lhs, const Rating& rhs) {
    return lhs.getScore() > rhs.getScore();
}

bool operator<=(const Rating& lhs, const Rating& rhs) {
    return lhs.getScore() <= rhs.getScore();
}

bool operator>=(const Rating& lhs, const Rating& rhs) {
    return lhs.getScore() >= rhs.getScore();
}

std::ostream& operator<<(std::ostream& os, const Rating& rating) {
    os << "사용자 id: " << rating.getUserId()
       << ", 영화 id: " << rating.getMovieId()
       << ", 평점: " << rating.getScore();
    return os;
}