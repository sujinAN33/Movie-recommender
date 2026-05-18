#include "MovieManager.h"
using namespace std;

void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
}


Movie* MovieManager::findMovieById(int movieId){
    for (auto& movie : movies) {
        if (movie.getId() == movieId) {
            return &movie;
        }
    }
    return nullptr;
}


Movie* MovieManager::findByTitle(const std::string& title){
    for (auto& movie : movies) {
        if (movie.getTitle() == title) {
            return &movie;
        }
    }
    std::cout << "영화를 찾을 수 없습니다: " << title << std::endl;
    return nullptr;
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

// BaseManager의 순수 가상 함수 구현
void MovieManager::loadFromFile(const std::string& filename)  {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
        return;
    } 
    string line;
    getline(file, line); // 헤더 스킵
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ','); int movieId= stoi(token);
        getline(ss, token, ','); string title = token;
        getline(ss, token, ','); double year=stod(token);

        movies.push_back(Movie(movieId, title, "", year)); // 장르와 개봉연도는 임시로 빈 문자열과 0으로 설정
    }
    file.close();

}

void MovieManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
        return;
    }
    file << "movieId,title,releaseYear\n"; // 헤더 작성
    for (const auto& movie : movies) {
        file << movie.getId() << ","
             << movie.getTitle() << ","
             << movie.getReleaseYear() << "\n";
    }
    file.close();
}

int MovieManager::size() const {
    return movies.size();
}



// 비교 연산자 오버로드
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