#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 최소로 알파벳 이동하는 방법
int minCnt(char cur, char target) {
    int forward = abs(cur - target); // 첫번째 위치 이용하지 않고 이동
    int backward = (cur - 'A' + 1) + ('Z' - target); // 첫번째 위치를 이용해서 이동
    return min(forward, backward);
}

// (인덱스, 현재 비용, 현재 문자열, 목표 문자열, 방문 횟수, answer)
void dfs(int i, int cost, string cur, string name, int visit[20], int* answer) {
    
    // 어떤 문자 위치를 3번 이상 방문하는것은 최소가 될 수 없음(방향을 두번 이상 틀면 비효율)
    if(visit[i]>2)
        return;
    
    // 위아래 이동 최소 비용 더함
    cost += minCnt(cur[i], name[i]);
    // 문자 변경
    cur[i] = name[i];
    
    if(cur == name) {
        *answer = min(*answer, cost);
        return;
    }

    if(i==0) {
        //문자 끝으로 이동
        visit[name.size()-1]++;
        dfs(name.size()-1, cost+1, cur, name, visit, answer);
        visit[name.size()-1]--;
        
        // 다음 위치로 이동
        visit[i+1]++;
        dfs(i+1, cost+1, cur, name, visit, answer);
        visit[i+1]--;
    } else if (i==name.size()-1) {
        // 첫 위치로 이동
        visit[0]++;
        dfs(0, cost+1, cur, name, visit, answer);
        visit[0]--;
        
        // 왼쪽으로 이동
        visit[i-1]++;
        dfs(i-1, cost+1, cur, name, visit, answer);
        visit[i-1]--;
    } else {
        //오른쪽 위치로 이동
        visit[i+1]++;
        dfs(i+1, cost+1, cur, name, visit, answer);
        visit[i+1]--;
        
        //왼쪽 위치로 이동
        visit[i-1]++;
        dfs(i-1, cost+1, cur, name, visit, answer);
        visit[i-1]--;
    }
    
}

int solution(string name) {
    int answer = 987654321;
    int visit[20]; // i번째 위치 방문 횟수
    fill(visit, &visit[20], 0);
    
    // 현재 문자열 상태
    string cur = "";
    for(int i=0; i<name.size(); i++)
        cur += "A";
    
    // 0번째 위치 방문 횟수 1 상태로 시작
    visit[0] = 1;
    dfs(0, 0, cur, name, visit, &answer);
    
    return answer;
}
