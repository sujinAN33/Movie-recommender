#pragma once

#include "Rating.h"
#include "User.h"
#include "Movie.h"
#include "BaseManager.h"

class RatingManager : public BaseManager {
private:
    std::vector<Rating> ratings;  // 모든 평점 데이터를 저장하는 벡터
public:
    bool addRating(Movie& movie, Rating& rating);  // 평점 추가
    void displayRatings(int movieId) const;  // 특정 영화의 평점 출력
    
    std::vector<Rating> findByUser(int userId) const;  // 특정 사용자의 평점 찾기
    std::vector<int> getAllUserIds() const;  // 모든 사용자 ID 반환

    void loadFromFile(const std::string& filename) override;   // 파일에서 평점 데이터 로드
    void saveToFile(const std::string& filename) const override;  // 평점 데이터를 파일에 저장
    int size() const override;  // 평점 데이터의 크기 반환
};

bool operator==(const Rating& lhs, const Rating& rhs);
bool operator!=(const Rating& lhs, const Rating& rhs);
bool operator<(const Rating& lhs, const Rating& rhs);
bool operator>(const Rating& lhs, const Rating& rhs);
bool operator<=(const Rating& lhs, const Rating& rhs);
bool operator>=(const Rating& lhs, const Rating& rhs);
std::ostream& operator<<(std::ostream& os, const Rating& rating);