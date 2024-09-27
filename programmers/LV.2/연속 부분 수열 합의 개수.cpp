#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    map<int, bool> m;
    
    for (int len = 1; len <= elements.size(); len++) { // 길이
        for (int startIdx = 0; startIdx < elements.size(); startIdx++) { // 시작 위치
            
            int sum = 0;
            for (int k = 0; k < len ; k++) { // 이동 거리
                sum += elements[(startIdx + k) % elements.size()];
            }
            
            if (m.find(sum) == m.end()) {
                answer++;
                m.insert({sum, true});
            }
        }
    }
    
    answer = m.size();
    
    return answer;
}
