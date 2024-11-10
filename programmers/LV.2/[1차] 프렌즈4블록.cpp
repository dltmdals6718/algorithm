#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    
    
    while (1) {
        bool flag = false;
        bool eraseBoard[m][n];
        fill(&eraseBoard[0][0], &eraseBoard[m-1][n], false);
        
        for (int i=0; i<m-1; i++) {
            for (int j=0; j<n-1; j++) {
                
                if (board[i][j] != 'X' && 
                    board[i][j] == board[i][j+1] &&
                    board[i+1][j] == board[i+1][j+1] &&
                    board[i][j] == board[i+1][j]) {
                    flag = true;
                    eraseBoard[i][j] = true;
                    eraseBoard[i][j+1] = true;
                    eraseBoard[i+1][j] = true;
                    eraseBoard[i+1][j+1] = true;
                }
            }
        }
                
        if (flag == false)
            break;
        
        
        
        for (int j=0; j<n; j++) { // 열
            queue<char> q;
            for (int i=m-1; i>=0; i--) { // 행
                if (!eraseBoard[i][j]) {
                    q.push(board[i][j]);
                } else {
                    answer++;
                }
            }
            
            for (int i=m-1; i>=0; i--) {
                
                if (!q.empty()) {
                    board[i][j] = q.front();
                    q.pop();
                } else {
                    board[i][j] = 'X';
                }
                
            }
        }
        
    }
    
    
    return answer;
}
