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

bool operator==(const Movie& lhs, const Movie& rhs) {
    return lhs.getTitle() == rhs.getTitle() &&
           lhs.getReleaseYear() == rhs.getReleaseYear();
}

bool operator!=(const Movie& lhs, const Movie& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Movie& lhs, const Movie& rhs) {
    if (lhs.getAverageRating() != rhs.getAverageRating()) {
        return lhs.getAverageRating() > rhs.getAverageRating();
    }
    return lhs.getTitle() < rhs.getTitle();
}

bool operator>(const Movie& lhs, const Movie& rhs) {
    return rhs < lhs;
}

bool operator<=(const Movie& lhs, const Movie& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const Movie& lhs, const Movie& rhs) {
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    os << "영화 ID: " << movie.getId() << "|"
       << "제목: " << movie.getTitle() << "|"
       << "장르: " << movie.getGenre() << "|"
       << "개봉연도: " << movie.getReleaseYear() << "|"
       << "평점: " << movie.getAverageRating() << " ("
       << movie.getRatingCount() << "명)";
    return os;
}