#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Movie.h" // Assuming Movie.h defines the Movie class
class MovieManager {
private:
    std::vector<Movie> movies; // Assuming Movie is a class that represents a movie
public:
    void addMovie(const Movie& movie);
    Movie* findMovieById(int movieId);
    void findByTitle(const std::string& title) const;
    void sortByRating() const;
    void printAll() const;

};

    bool operator==(const Movie& lhs, const Movie& rhs);
    bool operator!=(const Movie& lhs, const Movie& rhs);
    bool operator<(const Movie& lhs, const Movie& rhs);
    bool operator>(const Movie& lhs, const Movie& rhs);
    bool operator<=(const Movie& lhs, const Movie& rhs);
    bool operator>=(const Movie& lhs, const Movie& rhs);
    std::ostream& operator<<(std::ostream& os, const Movie& movie);