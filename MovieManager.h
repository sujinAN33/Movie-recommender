#include <stdio.h>
#include <vector>
#include <string>
#include "Movie.h" // Assuming Movie.h defines the Movie class
class MovieManager {
private:
    std::vector<Movie> movies; // Assuming Movie is a class that represents a movie
public:
    void addMovie(const Movie& movie);
    void findByTitle(const std::string& title) const;
    void sortByRating() const;
    void printAll() const;
};
