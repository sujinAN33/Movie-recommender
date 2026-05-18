#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include <vector>
#include "Rating.h"
#include "MovieManager.h"
#include "RatingManager.h"

class Recommender {
private:
    MovieManager& movieMgr; // 영화 매니저 객체
    RatingManager& ratingMgr; // 평점 매니저 객체
public:
    Recommender(MovieManager& m, RatingManager& r) : movieMgr(m), ratingMgr(r) {}
    int calculateSim(const std::vector<Rating>& user1, const std::vector<Rating>& user2);
    std::vector<std::pair<int, int>> findSimilarUsers(int targetUserId);
    void recommend(int targetUserId);
};
#endif // RECOMMENDER_H
