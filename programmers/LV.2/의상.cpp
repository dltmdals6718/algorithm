#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> m;
    for(int i=0; i<clothes.size(); i++) {
        if (m.find(clothes[i][1]) == m.end()) {
            m.insert({clothes[i][1], 1});
        } else {
            m[clothes[i][1]]++;
        }
    }
    
    answer = 1;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        answer *= (iter->second) + 1; // 안입는 경우 + 1
    }
    
    answer--; // 모두 안입는경우 제거
    
    
    return answer;
}
