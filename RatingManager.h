#pragma once
#include <vector>
#include <algorithm>
#include "Rating.h"
#include "User.h"
#include "Movie.h"

class RatingManager {
private:
    std::vector<Rating> ratings;  // 모든 평점 데이터를 저장하는 벡터
public:
    void addRating(Movie& movie, User& user, Rating& rating);  // 평점 추가
    void displayRatings() const;  // 모든 평점 출력
};