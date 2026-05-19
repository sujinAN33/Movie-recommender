#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include <vector>
#include "Rating.h"
#include "MovieManager.h"
#include "RatingManager.h"
#include "UserManager.h" //아직 사용하지는 않지만, 향후 사용자 기반 협업 필터링 구현 시 필요할 수 있음

class Recommender {
private:
    MovieManager& movieMgr; // 영화 매니저 객체
    RatingManager& ratingMgr; // 평점 매니저 객체
public:
    Recommender(MovieManager& m, RatingManager& r) : movieMgr(m), ratingMgr(r) {}
    double calculateSim(const std::vector<Rating>& user1, const std::vector<Rating>& user2);
    std::vector<std::pair<int, double>> findSimilarUsers(int targetUserId,int n);
    void recommend(int targetUserId, int n);
};
#endif // RECOMMENDER_H
