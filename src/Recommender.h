#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include <vector>
#include "Rating.h"
#include "MovieManager.h"
#include "RatingManager.h"

class Recommender {
private:
    MovieManager& movieMgr;
    RatingManager& ratingMgr;
public:
    static int calculateSim(const std::vector<Rating>& user1, const std::vector<Rating>& user2);
    static std::vector<std::pair<int, int>> findSimilarUsers(int targetUserId, const RatingManager& ratingMgr);
    static void recommend(int targetUserId, const RatingManager& ratingMgr);
};
#endif // RECOMMENDER_H
