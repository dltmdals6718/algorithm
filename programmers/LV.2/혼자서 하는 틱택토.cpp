#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int o=0;
    int x=0;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j]=='O')
                o++;
            else if(board[i][j]=='X')
                x++;
        }
    }
    
    int xWin = 0;
    int oWin = 0;
    
    // 가로
    for(int i=0; i<3; i++) {
        if (board[i][0]!='.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X')
                xWin++;
            else
                oWin++;
        }
    }

    // 세로
    for(int j=0; j<3; j++) {
        if (board[0][j]!='.' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X')
                xWin++;
            else
                oWin++;
        }
    }
    
    // 대각선
    if (board[0][0]!='.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X')
            xWin++;
        else
            oWin++;
    }
    if (board[2][0]!='.' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        if (board[2][0] == 'X')
            xWin++;
        else
            oWin++;
    }   
    
    // 승자가 1명이 아님
    if(oWin>0 && xWin>0)
        answer=0;
    
    // testCase 10 - 번갈아 놓지 않고 누군가 연속으로 놓아서 개수의 차이가 2이상임
    if(abs(x-o)>1)
        answer=0;
    
    // TestCase 2,5 - X가 O보다 많음
    if(x>o)
        answer=0;
    
    //선공이 이겼을때 x+1이 o여야함.
    if(oWin>0 && o!=x+1)
        answer=0;
    
    //후공이 이겼을때 x와o의 개수가 같아야함
    if(xWin>0 && o!=x)
        answer=0;
    
    return answer;
}
