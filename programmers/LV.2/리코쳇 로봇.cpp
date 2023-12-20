#include <string>
#include <vector>
#include <stack>
using namespace std;

int sol(vector<string> &board, pair<int, int> R, pair<int, int> G, int w, int h) {
    
    // (방향, 움직인 횟수, 현재 Y위치, 현재 X위치)
    stack<pair<int, pair<int, pair<int, int>>>> s;
    
    // 상하좌우, 0횟수, 시작Y, 시작X를 push
    for(int i=0; i<4; i++) {
        s.push(make_pair(i, make_pair(0, make_pair(R.first, R.second))));
    }
    
    // [Y][X] 좌표에 도달하는데 걸리는 최소 이동 횟수
    int cnt[100][100];
    fill(&cnt[0][0], &cnt[99][101], 10001);
    cnt[R.first][R.second] = 0; // 시작 위치는 0으로 초기화
    
    int dirOpr[2]; // dirOpr[0] : 이동해야할 Y 크기, dirOpr[1] : 이동해야할 X 크기
    while(!s.empty()) {
        int curY = s.top().second.second.first;
        int curX = s.top().second.second.second;
        int moveCnt = s.top().second.first; // 현재 위치의 이동 비용
        int dir = s.top().first; // 이동 방향
        s.pop();
        
        // dir(방향)에 따른 좌표의 상하좌우 이동 크기 Opr[0] : Y 방향, Opr[1] : X 방향
        if(dir==0) {
            dirOpr[0] = -1;
            dirOpr[1] = 0;
        } else if(dir==1) {
            dirOpr[0] = 1;
            dirOpr[1] = 0;
        } else if(dir==2) {
            dirOpr[0] = 0;
            dirOpr[1] = -1;
        } else {
            dirOpr[0] = 0;
            dirOpr[1] = 1;
        }
        
        while(1) {
            
            // 다음 위치에 장애물이 없고 벽에 부딪히지 않는다면. 다음 좌표로 이동.
            if(curY+dirOpr[0]>=0 && curY+dirOpr[0]<h && curX+dirOpr[1]>=0 && curX+dirOpr[1]<w && board[curY+dirOpr[0]][curX+dirOpr[1]] != 'D') {
                curY += dirOpr[0];
                curX += dirOpr[1];
            } else { // 장애물이 있거나 벽에 부딪혔다면.
                // 다음 위치를 이동 횟수를 최소로 도착한거라면 이동 비용 갱신하고, push.
                if(cnt[curY][curX]>moveCnt+1) {
                    cnt[curY][curX] = moveCnt+1;
                    
                    for(int i=0; i<4; i++) {
                        s.push(make_pair(i, make_pair(moveCnt+1, make_pair(curY, curX))));
                    }
                }
                break;
            }
        }
        
        
    }
    
    int answer = cnt[G.first][G.second];
    if(answer==10001)
        return -1;
    else
        return answer;
}

int solution(vector<string> board) {
    int answer = 0;
    pair<int, int> R, G; // 로봇, 목표위치 좌표
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            if(board[i][j]=='R')
                R = make_pair(i,j);
            else if(board[i][j]=='G')
                G = make_pair(i, j);
        }
    } 
    answer = sol(board, R, G, board[0].size(), board.size());
    return answer;
}
