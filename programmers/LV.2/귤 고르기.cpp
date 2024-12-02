#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for (int i=0; i<tangerine.size(); i++) {
        if (m.find(tangerine[i]) == m.end()) {
            m.insert({tangerine[i], 1});
        } else {
            m[tangerine[i]]++;
        }
    }
    
    
    vector<int> v;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        v.push_back(iter->second);
    }
    
    sort(v.rbegin(), v.rend());
    for (int i=0; i<v.size(); i++) {
        answer++;
        if (k - v[i] > 0) {
            k-=v[i];
        } else {
            break;
        }
    }
    
    return answer;
}
