#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> wait;
    for (int i=0; i<truck_weights.size(); i++) {
        wait.push(truck_weights[i]);
    }
    
    // (무게, 남은 거리)
    queue<pair<int, int>> q;
    while (!wait.empty()) {
        
        answer++;
        
        // 차량 한칸씩 이동
        int size = q.size();
        for (int i=0; i<size; i++) {
            if (q.front().second - 1 == 0) {
                weight += q.front().first;
                q.pop();
            } else {
                q.push(make_pair(q.front().first, q.front().second - 1));
                q.pop();
            }
        }
        
        
        // 차량 추가 가능?
        if (weight - wait.front() >= 0 && q.size() < bridge_length) {
            q.push(make_pair(wait.front(), bridge_length));
            weight -= wait.front();
            wait.pop();
        }
        
    }
    
    // 다리를 지나기 위해 기다리는 차량은 없어도 다리를 지나는중인 트럭이 있을 수 있음.
    int maxLen = 0;
    while (!q.empty()) {
        maxLen = max(maxLen, q.front().second);
        q.pop();
    }
    answer += maxLen;
    return answer;
}
