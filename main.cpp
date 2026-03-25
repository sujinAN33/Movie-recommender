// main.cpp
#include <iostream>
#include <vector>
#include "Movie.h"
#include "User.h"
#include "Rating.h"

int main() {
    std::vector<Movie> movies;

    // 영화 추가 (push_back)
    movies.push_back(Movie(1, "Inception",    "Sci-Fi",   2010));
    movies.push_back(Movie(2, "Parasite",     "Thriller", 2019));
    movies.push_back(Movie(3, "Interstellar", "Sci-Fi",   2014));

    // 평점 추가
    movies[0].addRating(4.8);
    movies[0].addRating(4.5);
    movies[1].addRating(5.0);

    // 전체 출력 (range-based for, const 참조)
    for (const Movie& m : movies) {
        m.display();
    }



    std::cout << "총 " << movies.size() << "편" << std::endl;

    std::vector<User> users;
    users.push_back(User(1, "Alice", "alice@example.com"));
    users.push_back(User(2, "Bob",   "bob@example.com"));
    users.push_back(User(3, "Charlie", "charlie@example.com"));

    for(const User& u : users) {
        u.display();
    }  

    std::cout<<"총"<<users.size()<<"명"<<std::endl;


    std::vector<Rating> ratings;
    ratings.push_back(Rating(1, 1, 4.8)); // Alice가 Inception에 4.8점
    ratings.push_back(Rating(2, 1, 4.5)); // Bob이 Inception에 4.5점
    ratings.push_back(Rating(1, 2, 5.0)); // Alice가 Parasite에 5.0점

    for(const Rating& r : ratings) {
        r.display();
    }

    std::cout<<"총 별점 : "<<ratings.size()<<"개"<<std::endl;

    

}