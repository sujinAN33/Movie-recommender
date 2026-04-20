#pragma once
#include <iostream>
class Rating {
private:
    int userId;
    int movieId;
    double score;  
public:
    Rating();  // 기본 생성자 추가
    Rating(int userId, int movieId, double score);

    int getUserId() const;
    int getMovieId() const;
    double getScore() const;
    void display() const;

    //연산자 오버로딩
    bool operator==(const Rating& other) const;
    bool operator!=(const Rating& other) const;
    bool operator<(const Rating& other) const;
    bool operator>(const Rating& other) const;
    bool operator<=(const Rating& other) const;
    bool operator>=(const Rating& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Rating& rating);
};