#include "RatingManager.h"

void RatingManager::addRating(Movie& movie,User& user,Rating& rating){
    if(movie.getId() != rating.getMovieId()){
        std::cerr << "영화의 id와 평점의 영화 id가 일치하지 않습니다." << std::endl;
        return;
    }
    else if(user.getId() != rating.getUserId()){
        std::cerr << "본인의 id와 평점의 사용자 id가 일치하지 않습니다." << std::endl;
        return;
    }
    else{
        ratings.push_back(rating);
        movie.addRating(rating.getScore());  // movie에도 똑같이 평점 추가
    }
    
}
void RatingManager::displayRatings() const {
    for (const auto& rating : ratings) {
        std::cout << rating << std::endl;
    }
}