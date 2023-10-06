#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> m;
    for(int i=0; i<s.length(); i++) {
        
        // 첫 글자라면
        if(m.find(s[i])==m.end()) {
            answer.push_back(-1); 
            m.insert({s[i], i});
        } else {
            answer.push_back(i-m[s[i]]); // 현재 문자의 위치 i에서 앞서 나타난 해당 문자의 위치를 빼면 두 문자 사이의 거리
            m[s[i]]=i; // 현재 문자의 위치를 최신화
        }
        
        
    }
    
    return answer;
}
