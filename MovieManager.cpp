#include "MovieManager.h"


void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
}

Movie* MovieManager::findMovieById(int movieId) {
    for (auto& movie : movies) {
        if (movie.getId() == movieId) {
            return &movie;
        }
    }
    return nullptr;
}


void MovieManager::findByTitle(const std::string& title) const {
    for (const auto& m : movies) {
        if (m.getTitle() == title) {
            std::cout << m << std::endl;
            return;
        }
    }
    std::cout << "영화를 찾을 수 없습니다: " << title << std::endl;
}
void MovieManager::sortByRating() const {
    std::vector<Movie> sortedMovies = movies; // 원본 유지 위해 복사
    std::sort(sortedMovies.begin(), sortedMovies.end(),
              [](const Movie& a, const Movie& b) {
                  if (a.getAverageRating() != b.getAverageRating()) {
                      return a.getAverageRating() > b.getAverageRating();
                  }
                  return a.getTitle() < b.getTitle();
              }); // 평점 내림차순 정렬(동점이면 제목 오름차순)
    for (const auto& m : sortedMovies) {
        std::cout << m << std::endl;
    }
}
void MovieManager::printAll() const {
    for (const auto& m : movies) {
        std::cout << m << std::endl;
    }
}   