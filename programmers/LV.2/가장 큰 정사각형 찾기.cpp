#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            if(board[i][j]==1) {
                answer=max(answer, 1); // 1x1 정사각형이 있다면 정답은 최소 1이다.
                
                if(j-1>=0 && i-1>=0) { // 좌상단 대각선, 좌, 위로 이동이 가능하다면.
                    board[i][j] = min(board[i-1][j], board[i][j-1]);
                    board[i][j] = min(board[i][j], board[i-1][j-1]); // 3방향중 최소값 찾기.
                    board[i][j]+=1; // 최소값+1
                    answer=max(answer, board[i][j]*board[i][j]); // 넓이 갱신
                }
            }
        }
    }

    return answer;
}
