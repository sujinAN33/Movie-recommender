#include "Movie.h"
#include <iostream>

// 기본 생성자
Movie::Movie()
    : id(0), releaseYear(0),
      totalRating(0.0), ratingCount(0) {}

// 4인자 생성자
Movie::Movie(int id, const std::string& title,
             const std::string& genre, int year)
    : id(id), title(title), genre(genre),
      releaseYear(year),
      totalRating(0.0), ratingCount(0) {}

int         Movie::getId()           const { return id; }
std::string Movie::getTitle()        const { return title; }
std::string Movie::getGenre()        const { return genre; }
int         Movie::getReleaseYear()  const { return releaseYear; }
int         Movie::getRatingCount()  const { return ratingCount; }

double Movie::getAverageRating() const {
    if (ratingCount == 0) return 0.0;   // 0 나눗셈 방어
    return totalRating / ratingCount;
}

void Movie::addRating(double r) {
    if (r < 0.0 || r > 5.0) return;    // 유효성 검사
    totalRating += r;
    ratingCount++;
}


// 연산자 오버로딩
bool Movie::operator==(const Movie& other) const {
    return title==other.title&& releaseYear==other.releaseYear;
}

bool Movie::operator!=(const Movie& other) const {
    return !(*this == other);
}

bool Movie::operator<(const Movie& other) const {
    if (getAverageRating() != other.getAverageRating()) {
        return getAverageRating() > other.getAverageRating();
    }
    return title < other.title;  // 평균 평점이 같으면 제목 오름차순
}

bool Movie::operator>(const Movie& other) const {return other < *this;}
bool Movie::operator<=(const Movie& other) const {return !(*this > other);}
bool Movie::operator>=(const Movie& other) const {return !(*this < other);}

std::ostream& operator<<(std::ostream& os,const Movie& m){
    os<< "영화 ID: " << m.id << "|"
    << "제목: " << m.title << "|"
    << "장르: " << m.genre << "|"
    << "개봉연도: " << m.releaseYear << "|"
    << "평점: " << m.getAverageRating() << " (" << m.getRatingCount() << "명)\n";
    return os;
}