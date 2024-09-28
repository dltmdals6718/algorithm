#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    
    if (a.first <= b.first)
        return true;
    else
        return false;
    
}


int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    map<int, int> m;
    
    for (int i=0; i<priorities.size(); i++) {
        if (m.find(priorities[i]) == m.end())
            m.insert({priorities[i], 1});
        else
            m[priorities[i]]++;
    }
    
    vector<pair<int, int>> v; // <원소, 개수> 실행시켜야할 우선순위의 원소값과 개수
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        v.push_back(make_pair(iter->first, iter->second));
    }
    

    sort(v.rbegin(), v.rend(), comp);
    
    queue<pair<int, int>> q; // <원소, 인덱스>
    
    for (int i=0; i<priorities.size(); i++)
        q.push(make_pair(priorities[i], i));
    

    while (!q.empty()) {
        
        cout<<q.front().first<<" "<<q.front().second<<endl;
        
        if (v[0].first == q.front().first) { // 실행해야할 우선순위와 큐의 첫번째 우선순위가 같다면
            
            if (q.front().second == location) {
                answer++;
                q.pop();
                break;
            } else {
                answer++;
                q.pop();
                v[0].second -= 1;
                
                if (v[0].second == 0)
                    v.erase(v.begin());
            }
        } else {
            q.push(make_pair(q.front().first, q.front().second));
            q.pop();
        }
        
    }
    
    
    return answer;
}
