#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    
    for (int i=0; i<land.size(); i++) {
        for(int j=0; j<4; j++) {
            
            if (i>0) {
                
                int score = land[i][j];
                for (int k=0; k<4; k++) {
                    if (j != k) {
                        land[i][j] = max(land[i][j], score + land[i-1][k]);
                    }
                }
                
            }
            
        }
    }
    
    for (int i=0; i<4; i++) {
        answer = max(answer, land[land.size()-1][i]);
    }

    return answer;
}
