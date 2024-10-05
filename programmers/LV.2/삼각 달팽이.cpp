#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int arr[1001][1001];
    fill(&arr[0][0], &arr[1000][1001], -1);
    
    // 아래 -> 오른쪽 -> 대각선 왼쪽 위 -> 아래를 반복
    
    
    int y = -1;
    int x = 0;
    int dir = 0;
    int move[3][2] = {{1, 0}, {0, 1}, {-1, -1}}; // 아래, 오른쪽, 대각선 왼쪽 위
    int cnt = 1;
    
    vector<int> v[1001];
    
    
    int len = n;
    
     // n이 4일때 4개 이동 + 방향 틀고 3개이동 + 방향 틀고 2개이동 + 1 이므로 1부터n까지 합만큼 이동함.
    while (len > 0) {
        
        for (int i = 0; i<len; i++) {
            arr[y + move[dir][0]][x + move[dir][1]] = cnt;
            y += move[dir][0];
            x += move[dir][1];
            cnt++;
        }
    
        
        dir = (dir + 1) % 3;
        len--;
    }

    
    for (int i=0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    
    
    
    return answer;
}
