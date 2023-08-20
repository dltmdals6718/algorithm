#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 98; // 최악의 경우는 99개의 송전탑과 1개의 송전탑으로 나뉨
    
    bool visit[101];
    
    vector<int> v[101]; // v[X]에서 갈 수 있는 송전탑을 저장
    
    for(int i=0; i<wires.size(); i++) {
        v[wires[i][0]].push_back(wires[i][1]); // 양방향
        v[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=0; i<wires.size(); i++) { // wires[i]의 길이 끊어졌다고 가정
        fill(visit, visit+101, false);
        stack<int> s;
        vector<int> size; // 무조건 두개로 쪼개지며 각각의 크기를 담을 것임. 
        
        for(int j=1; j<=n; j++) { // 송전탑 1부터 n까지 DFS
            if(!visit[j]) { // j번 송전탑 미방문 상태라면
                int cnt=0; // 현재 방문한 송전탑의 개수
                visit[j]=true;
                s.push(j);
                while(!s.empty()) { // DFS 탐색
                    int cur = s.top();
                    s.pop();
                    for(int k=0; k<v[cur].size(); k++) { // v[cur]에 담긴건 cur과 연결된 송전탑들의 번호임
                        if(!visit[v[cur][k]]&&(cur!=wires[i][0]||v[cur][k]!=wires[i][1])
                           &&(cur!=wires[i][1]||v[cur][k]!=wires[i][0])) { // 다음 송전탑이 미방문 상태이고, wires[i]가 끊어졌다고 가정했기에 끊어진 방향인지 아닌지 검사
                            visit[v[cur][k]]=true;
                            cnt++;
                            s.push(v[cur][k]);
                        }
                    }
                }
                size.push_back(cnt); // 연결된 송전탑의 개수 push
            }
        }
        // 두개로 쪼개진 송전탑의 크기 차가 answer보다 작다면 갱신
        answer = min(answer, size[0]-size[1]>=0?size[0]-size[1]:size[1]-size[0]);
    }
    
    
    return answer;
}
