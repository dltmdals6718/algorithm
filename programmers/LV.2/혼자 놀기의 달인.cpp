#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int DFS(int idx, bool visit[], vector<int> &cards) {
    
    int sum = 1;
    while(!visit[cards[idx]-1]) {
        idx = cards[idx]-1;
        visit[idx] = true;
        sum += 1;
    }

    return sum;
}


int solution(vector<int> cards) {
    int answer = 0;
    
    bool visit[101];
    vector<int> v;
    fill(&visit[0], &visit[101], false);
    for(int i=0; i<cards.size(); i++) {
        if(!visit[i]) {
            visit[i] = true;
            int result = DFS(i, visit, cards);
            v.push_back(result);
        }
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    for(int i=0; i<v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    
    if(v.size()>=2) {
        answer = v[0] * v[1];
    }
    return answer;
}
