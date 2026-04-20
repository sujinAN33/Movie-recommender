#include "MovieManager.h"


void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
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
    std::sort(sortedMovies.begin(), sortedMovies.end()); // 내림차순 정렬
    for (const auto& m : sortedMovies) {
        std::cout << m << std::endl;
    }
}
void MovieManager::printAll() const {
    for (const auto& m : movies) {
        std::cout << m << std::endl;
    }
}   