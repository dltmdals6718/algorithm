#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, less<int>> pq;
    
    int i=0;
    for(; i<enemy.size(); i++) {
        if(n-enemy[i]>=0) {
            n-=enemy[i];
            pq.push(enemy[i]);
        } else {
            if(k>=1) {
                if(!pq.empty() && pq.top() >= enemy[i]) { //pq.top() >= enemy[i]....
                    n+=pq.top();
                    pq.pop();
                    
                    n-=enemy[i]; // 주의. 무적권을 사용하더라도 pq에 push 해줘야함.
                    pq.push(enemy[i]);
                }
                k--; // 지난 라운드에 손해본 병사가 없어도 쉴드는 사용할 수 있으므로 여기에서 k-- 존재.
            } else {
                break;
            }
        }
    }
    
    
    return i;
}
