#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    // cache 뒤쪽에 있을수록 최근에 사용한것임.
    vector<string> cache;
    for(int i=0; i<cities.size(); i++) {
        
        // 도시를 소문자로 변환
        for(int j=0; j<cities[i].length(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
        
        
        // 캐시에서 도시 검색
        int idx=-1;
        for(int j=0; j<cache.size(); j++) {
            if(cities[i] == cache[j]) {
                idx=j;
            }
        }
        
        if(idx==-1) { // 캐시에 존재하지 않음
            answer+=5;
        
            // empty() 체크 안하면 cache 크기 0과 cacheSize 0이 일치해버려서 없는 빈 cache에서 erase가 일어나 fault!
            if(!cache.empty() && cache.size()==cacheSize){ // 캐시 자리가 없다면
                cache.erase(cache.begin());
            }
            if(cacheSize>0) { // 캐시 크기가 0 초과라면 캐시를 쓸 수 있다.
                cache.push_back(cities[i]);
            }
            
        } else { // 캐시에 존재함
            answer+=1;
            cache.erase(cache.begin()+idx); // 캐시에서 삭제후
            cache.push_back(cities[i]); // 맨 뒤로 보내주기 (vector 뒤로 갈수록 최근에 사용한 것임.)
        }   
    }
    
    return answer;
}
