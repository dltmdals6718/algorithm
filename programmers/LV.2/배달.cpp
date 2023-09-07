#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    map<pair<int,pair<int,int>>, bool> m; // a에서 b로 가는데 드는 비용 c 방문 여부 ex:{(A,B,10), true}
    bool able[51]; // i 마을 방문 가능 여부
    fill(able, able+51, false);
    
    vector<pair<int, int>> v[51]; // a에서 b로 가는 비용 (a, b, cost)
    for(int i=0; i<road.size(); i++) {
        // 양방향
        v[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        v[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    
    stack<pair<int,int>> s; // (현재 위치, 현재 총 비용)
    s.push(make_pair(1, 0)); // 1번 마을부터 시작. 현재 0 비용
    able[1]=true;
    
    while(!s.empty()) {
        int cur = s.top().first; // 현재 위치
        int cost = s.top().second; // 현재 비용
        s.pop();
        
        for(int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i].first; // 다음 마을
            int nextCost = v[cur][i].second; // 다음 마을 도로의 비용
            if(m.find(make_pair(cur,make_pair(next, cost+nextCost)))==m.end() // a->b 비용 c를 방문한 적이 없다면
               && cost+nextCost<=K // 현재 비용과 다음 마을까지 이동 비용 합이 K보다 작거나 같다면
               && next!=1) { // 다음 마을은 1번 마을이 아니여야함
                s.push(make_pair(next, cost+nextCost)); // 다음 마을 번호와 총 비용 push
                m.insert({make_pair(cur, make_pair(next, cost+nextCost)), true}); // a->b의 비용 저장
                able[next]=true; // cur의 다음 마을인 next 배달이 가능하므로 able에 true로.
            }
        }
    }
    
    for(int i=1; i<=N; i++) { // 방문 가능한 마을 카운트
        if(able[i])
            answer++;
    }

    return answer;
}
