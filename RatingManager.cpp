#include "RatingManager.h"

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

void RatingManager::displayRatings(const int movieId) const {
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