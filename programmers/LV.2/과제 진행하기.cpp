#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool comp(vector<string> a, vector<string> b) {
    
    a[1].erase(a[1].begin()+2);
    b[1].erase(b[1].begin()+2);
    
    if(stoi(a[1]) < stoi(b[1])) {
        return true;
    } else {
        return false;
    }
    
}


vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<int, string>> s; // (남은 과제 시간, 과제명)
    
    sort(plans.begin(), plans.end(), comp); // 시간순 정렬 ":" 문자를 지우고 크기 비교로 오름차순 정렬.
    for(int i=0; i<plans.size(); i++) {
        
        // 현재 과제 시작 시각
        int curTime = stoi(plans[i][1].substr(0,2)) * 60
            + stoi(plans[i][1].substr(3,2));
        
        // 현재 과제 완료까지 걸리는 시간
        int curPlayTime = stoi(plans[i][2]);
        
        if(i+1<plans.size()) { // 다음 새로운 과제가 존재하면
            
            // 다음 과제 시작 시각
            int nextTime = stoi(plans[i+1][1].substr(0,2)) * 60
            + stoi(plans[i+1][1].substr(3,2));
            
            // 다음 과제 완료까지 걸리는 시간
            int nextPlayTime =  stoi(plans[i+1][2]);
            
            // 현재 과제가 다음 과제 시작 시각전에 완료가 가능하고 시간이 남는다면
            if(curTime + curPlayTime < nextTime) {
                answer.push_back(plans[i][0]);
                
                // 남은 과제 가능 시간
                int restTime = (nextTime) - (curTime + curPlayTime);
                
                while(!s.empty()) {
                    
                    // 남은 과제를 가능 시간안에 끝낼 수 있다면
                    if(s.top().first<=restTime) {
                        answer.push_back(s.top().second);
                        restTime -= s.top().first;
                        s.pop();
                    } else {
                        // 남은 과제를 완전히 끝내지 못하더라도 남은 시간만이라도 수행
                        string report = s.top().second;
                        int restReportTime = s.top().first;
                        s.pop();
                        s.push(make_pair(restReportTime - restTime, report));
                        break;
                    }
                    
                }
                
                // 다음 과제 시작 시각에 딱 맞춰 현재 과제를 끝냄
            } else if (curTime + curPlayTime == nextTime) {
                answer.push_back(plans[i][0]);
            }
            else { // 현재 과제를 다음 과제 시작전에 다 못 끝냄
                s.push(make_pair( (curTime+curPlayTime) - (nextTime), plans[i][0]));
            }
            
            
        } else { // 마지막 새로운 과제라면 수행하고 멈춰둔 과제들 순서대로 진행
            answer.push_back(plans[i][0]);
            
            while(!s.empty()) { // 멈춰둔 과제들 순서대로 진행
                answer.push_back(s.top().second);
                s.pop();
            }
        }
        
        
        
    }
    
    return answer;
}
