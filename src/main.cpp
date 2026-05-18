#include <iostream>
#include "Recommender.h"
#include "RatingManager.h"

int main(){
    RatingManager ratingMgr;
    ratingMgr.loadFromFile("data/ratings.csv"); // 평점 데이터 로드

    int targetUserId = 1; // 추천을 받을 사용자 ID
    Recommender::recommend(targetUserId, ratingMgr); // 추천 실행

    return 0;
 
}