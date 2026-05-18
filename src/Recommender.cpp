#include "Recommender.h"
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int Recommender::calculateSim(const vector<Rating>& user1, const vector<Rating>& user2) {
    int commonCount=0; //공통으로 본 영화 수
    int scoreDiffSum=0; //평점 차이의 합
    for (const Rating& r1 : user1) {
        for (const Rating& r2 : user2) {
            if (r1.getMovieId() == r2.getMovieId()) {
                commonCount++;
                scoreDiffSum += abs(r1.getScore() - r2.getScore());
                
            }
            
        }
    }
    if (commonCount == 0) {
        return -100; //공통으로 본 영화가 없는 경우, 유사도는 -100으로 설정
    }
    return commonCount * 10 - scoreDiffSum; //유사도 계산: 공통 영화 수 * 10 - 평점 차이의 합
}
vector<pair<int, int>> Recommender::findSimilarUsers(int targetUserId, const RatingManager& ratingMgr) {
    vector<pair<int,int>> sims; // {사용자 ID, 유사도} 쌍을 저장할 벡터
    vector<Rating> myRatings = ratingMgr.findByUser(targetUserId);


    for(int otherId:ratingMgr.getAllUserIds()){
        if(otherId==targetUserId) continue; // 자기 자신은 비교에서 제외
        vector<Rating> otherRatings = ratingMgr.findByUser(otherId);
        int sim=calculateSim(myRatings,otherRatings);
        sims.push_back({otherId, sim});
    }
    sort(sims.begin(), sims.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.second > b.second; //유사도가 높은 순으로 정렬
    });
    if(sims.empty() || sims[0].second <= -100){
        return {}; // 유사한 사용자가 없으면 빈 벡터 반환
    }
    if (sims.size() > 3) {
        sims.resize(3); // 상위 3명만 남김
    }

    return sims;
}
void Recommender::recommend(int targetUserId, const RatingManager& ratingMgr) {
    MovieManager movieMgr; // 영화 매니저 객체 생성
    vector<pair<int,int>> sims=findSimilarUsers(targetUserId,ratingMgr);
    map<int, int> movieReommendScore; // 영화 ID별 추천 점수 저장
    //유사도 높은 순으로 정렬

    //내가 본 영화 목록
    set<int> myMovieIds;
    for(const Rating& r:ratingMgr.findByUser(targetUserId)){
        myMovieIds.insert(r.getMovieId());
    }
    //유사한 사용자들이 본 영화 중 내가 안 본 영화 찾기
    for(const auto& sim:sims){
        int otherId=sim.first;
        for(const Rating& r:ratingMgr.findByUser(otherId)){
            if(myMovieIds.find(r.getMovieId())==myMovieIds.end()){ //내가 안 본 영화라면
                Movie* m=movieMgr.findMovieById(r.getMovieId());
                if(m){ //영화 정보가 존재하면
                    movieReommendScore[r.getMovieId()]+=sim.second; //유사도 점수 누적
                }
                
            }
        }
    }
    //추천 점수가 높은 순으로 정렬
    //map을 벡터로 변환하여 정렬
    vector<pair<int, int>> sorted(movieReommendScore.begin(), movieReommendScore.end());
    sort(sorted.begin(), sorted.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 추천 점수가 높은 순으로 정렬
    });

    //정렬된 추천 영화 출력
    for (const auto& rec : sorted) {
        Movie* m = movieMgr.findMovieById(rec.first);
        if (m) {
            cout << "추천 영화: " << m->getTitle() << " (추천 점수: " << rec.second << ")" << endl;
        }
    }
}