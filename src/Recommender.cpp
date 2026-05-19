#include "Recommender.h"
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
double Recommender::calculateSim(const vector<Rating>& user1, const vector<Rating>& user2) {
    int commonCount=0; //공통으로 본 영화 수
    double scoreDiffSum=0; //평점 차이의 합
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
   
    return commonCount * commonCount - scoreDiffSum; //유사도 계산: 공통 영화 수 제곱 - 평점 차이의 합(평점 차이 최대 5.0)
    //공통 영화 수가 많을수록 유사도가 크게 높아짐, 평점 차이가 클수록 유사도가 낮아짐
    //만약 공통 영화가 3개이고, 평점 차이의 합이 4.0이라면, 유사도는 3*3 - 4.0 = 5.0이 됨
}
vector<pair<int, double>> Recommender::findSimilarUsers(int targetUserId, int n) {
    vector<pair<int,double>> sims; // {사용자 ID, 유사도} 쌍을 저장할 벡터
    vector<Rating> myRatings = ratingMgr.findByUser(targetUserId);


    for(int otherId:ratingMgr.getAllUserIds()){
        if(otherId==targetUserId) continue; // 자기 자신은 비교에서 제외
        vector<Rating> otherRatings = ratingMgr.findByUser(otherId);
        double sim=calculateSim(myRatings,otherRatings);
        if(sim<0){
            continue; // 유사도가 음수인 경우, 유사한 사용자가 아니므로 제외
        }
        sims.push_back({otherId, sim});// 유사도가 0 이상인 사용자만 sims 벡터에 추가
    }
    sort(sims.begin(), sims.end(), [](const pair<int,double>& a, const pair<int,double>& b){
        return a.second > b.second; //유사도가 높은 순으로 정렬
    });
    if(sims.empty() || sims[0].second <= -100){
        return {}; // 유사한 사용자가 없으면 빈 벡터 반환
    }
    
    if (sims.size() > n) {
        sims.resize(n); // 상위 n명만 남김
    }
    //n명보다 유사한 사용자가 적을 경우, 유사한 사용자 모두 반환

    return sims;
}
void Recommender::recommend(int targetUserId, int n) {
    vector<pair<int,double>> sims=findSimilarUsers(targetUserId, n);
    map<int, double> movieReommendScore; // 영화 ID별 추천 점수 저장
    //유사도 높은 순으로 정렬

    //내가 본 영화 목록
    set<int> myMovieIds;
    for(const Rating& r:ratingMgr.findByUser(targetUserId)){
        myMovieIds.insert(r.getMovieId());
    }
    //내가 본 영화가 없다면
    if(myMovieIds.empty()){
        cout << "아직 시청한 영화가 없습니다. 영화를 시청하고 평점을 남겨주세요." << endl;
        return;
    }
    //유사한 사용자들이 본 영화 중 내가 안 본 영화 찾기
    for(const auto& sim:sims){//유사한 사용자들
        int otherId=sim.first;
        for(const Rating& r:ratingMgr.findByUser(otherId)){//유사한 사용자가 본 영화의 평점들
            if(myMovieIds.find(r.getMovieId())==myMovieIds.end()){ //내가 안 본 영화라면
                Movie* m=movieMgr.findMovieById(r.getMovieId());
                if(m){ //영화 정보가 존재하면
                    movieReommendScore[r.getMovieId()]+=r.getScore()*sim.second; //영화의 추천 점수에 유사한 사용자의 평점*유사도 더하기
                    //유사한 사용자가 평가한 평점이 높고 , 그 유사 사용자의 유사도가 높을수록 추천 점수가 높아짐
                }
                
            }
        }
    }
    //공통 영화가 0개이면
    if(movieReommendScore.empty()){
        cout << "추천을 위한 평점 기록이 부족합니다. 몇 편 더 시청해볼까요?" << endl;
        return;
    }
    //추천 점수가 높은 순으로 정렬
    //map을 벡터로 변환하여 정렬
    vector<pair<int, double>> sorted(movieReommendScore.begin(), movieReommendScore.end());
    sort(sorted.begin(), sorted.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
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