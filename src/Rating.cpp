#include "Rating.h"
#include <iostream>
using namespace std;

Rating::Rating() : userId(0), movieId(0), score(0.0) {}  // 기본 생성자
Rating::Rating(int userId, int movieId, double score)
    : userId(userId), movieId(movieId) {
        if (score < 0.0|| score > 5.0) score = 0.0;   // 유효성 검사
        this->score = score;
    } // 초기화 리스트

int Rating::getUserId() const { return userId; }
int Rating::getMovieId() const { return movieId; }
double Rating::getScore() const { return score; }
