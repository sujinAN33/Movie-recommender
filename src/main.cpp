#include <iostream>
#include "Recommender.h"
#include "RatingManager.h"
#include "MovieManager.h"

int main(){
    RatingManager ratingMgr;
    ratingMgr.loadFromFile("data/ratings.csv"); // 평점 데이터 로드
    MovieManager movieMgr;
    movieMgr.loadFromFile("data/movies.csv"); // 영화 데이터 로드
    Recommender recommender(movieMgr, ratingMgr);

    int targetUserId = 1; // 추천을 받을 사용자 ID
    recommender.recommend(targetUserId,3); // 추천 실행

    return 0;
 
}