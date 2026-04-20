// main.cpp
#include <limits>
#include "MovieManager.h"
#include "UserManager.h"
#include "RatingManager.h"
#include "Movie.h"
#include "User.h"
#include "Rating.h"

int main() {
    MovieManager movieManager;
    UserManager userManager;
    RatingManager ratingManager;

    bool running = true;

    while(running){
        int choice;

        std::cout << "==============================" << std::endl;
        std::cout<<"[영화]"<<std::endl;
        std::cout << "1. 영화 추가" << std::endl;
        std::cout << "2. 제목으로 검색" << std::endl;
        std::cout << "3. 전체 목록 출력" << std::endl;
        std::cout << "4. 평점으로 정렬" << std::endl;
        std::cout << std::endl;
        std::cout <<"[사용자]"<<std::endl;
        std::cout << "5. 사용자 추가" << std::endl;
        std::cout << "6. 사용자 목록 출력" << std::endl;
        std::cout << std::endl;
        std::cout <<"[평점]"<<std::endl;
        std::cout << "7. 평점 입력" << std::endl;
        std::cout << "8. 영화별 전체 평점 목록 조회" << std::endl;
        std::cout << std::endl;
        std::cout << "9. 종료" << std::endl;
        std::cout<< "선택: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "숫자를 입력해주세요. (1~9)" << std::endl;
            std::cout << std::endl;
            continue;
        }

        switch(choice) {
            case 1: {
                std::string title, genre;
                int id, releaseYear;
                std::cout<< "영화 id: ";
                std::cin>> id;
                std::cout<< "영화 제목: ";
                std::getline(std::cin >> std::ws, title);
                std::cout<< "장르: ";
                std::getline(std::cin >> std::ws, genre);
                std::cout<< "개봉연도: ";
                std::cin>> releaseYear;

                movieManager.addMovie(Movie(id, title, genre, releaseYear));
                std::cout<< "영화가 추가되었습니다." << std::endl;
                std::cout << std::endl;
                break;

            }
            case 2: {
                std::string title;
                std::cout<< "검색할 영화 제목: ";
                std::getline(std::cin >> std::ws, title);
                movieManager.findByTitle(title);
                std::cout << std::endl;

                break;
            }
            case 3: {
                movieManager.printAll();
                std::cout << std::endl;
                break;
            }
            case 4: {
                movieManager.sortByRating();
                std::cout << std::endl;
                break;
            }
            case 5: {
                int userId;
                std::string name, email;
                std::cout<< "사용자 id: "; 
                std::cin>> userId;
                std::cout<< "사용자 이름: ";
                std::cin>> name;
                std::cout<< "사용자 이메일: ";
                std::cin>> email;
                userManager.addUser(User(userId, name, email));
                std::cout<< "사용자가 추가되었습니다." << std::endl;
                std::cout << std::endl;
                break;

            }

            case 6: {
                userManager.printUsers();
                std::cout << std::endl;
                break;
            }
            case 7: {
                int userId, movieId;
                double score;
                std::cout<< "사용자 id: ";
                std::cin>> userId;
                std::cout<< "영화 id: ";
                std::cin>> movieId;
                std::cout<< "평점 (0.0 ~ 5.0): ";
                std::cin>> score;

                User* user = userManager.findUserById(userId);
                if (user == nullptr) {
                    std::cout << "등록된 사용자가 없습니다. 먼저 사용자를 추가해주세요." << std::endl;
                    std::cout << std::endl;
                    break;
                }

                Movie* movie = movieManager.findMovieById(movieId);
                if (movie == nullptr) {
                    std::cout << "등록된 영화가 없습니다. 먼저 영화를 추가해주세요." << std::endl;
                    std::cout << std::endl;
                    break;
                }

                Rating rating(userId, movieId, score);

                if (ratingManager.addRating(*movie, rating)) {
                    std::cout<< "평점이 추가되었습니다." << std::endl;
                }
                std::cout << std::endl;
                break;
            }
            case 8: {
                int movieId;
                std::cout << "평점을 조회할 영화 id: ";
                std::cin >> movieId;
                ratingManager.displayRatings(movieId);
                std::cout << std::endl;
                break;
            }
            case 9: {
                std::cout << "프로그램을 종료합니다." << std::endl;
                std::cout << std::endl;
                running = false;
                break;
            }
            default: {
                std::cout << "잘못된 선택입니다. 다시 시도해주세요." << std::endl;
                std::cout << std::endl;

                break;
            }
        }
    }

    

}