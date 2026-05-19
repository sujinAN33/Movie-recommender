#pragma once
#include "Movie.h" 
#include "BaseManager.h" 
class MovieManager : public BaseManager {
private:
    std::vector<Movie> movies; 
public:
    void addMovie(const Movie& movie);
    Movie* findMovieById(int movieId);
    Movie* findByTitle(const std::string& title);
    void sortByRating() const;
    void printAll() const;
    void loadFromFile(const std::string& filename) override;
    void saveToFile(const std::string& filename) const override;
    int size() const override;

};

    bool operator==(const Movie& lhs, const Movie& rhs);
    bool operator!=(const Movie& lhs, const Movie& rhs);
    bool operator<(const Movie& lhs, const Movie& rhs);
    bool operator>(const Movie& lhs, const Movie& rhs);
    bool operator<=(const Movie& lhs, const Movie& rhs);
    bool operator>=(const Movie& lhs, const Movie& rhs);
    std::ostream& operator<<(std::ostream& os, const Movie& movie);