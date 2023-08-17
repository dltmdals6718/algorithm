#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int BFS(int y, int x, vector<string>* maps, bool (*visit)[101]) {
    
    queue<pair<int,int>> q;
    int sum=0;
    q.push(make_pair(y,x));
    visit[y][x] = true;
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        sum+=((*maps)[curY][curX])-'0';
        q.pop();
        
        if(curY-1>=0&&!visit[curY-1][curX]&&(*maps)[curY-1][curX]!='X') {
            visit[curY-1][curX] = true;
            q.push(make_pair(curY-1, curX));
        }
        if(curY+1<maps->size()&&!visit[curY+1][curX]&&(*maps)[curY+1][curX]!='X') {
            visit[curY+1][curX] = true;
            q.push(make_pair(curY+1, curX));
        }
        if(curX-1>=0&&!visit[curY][curX-1]&&(*maps)[curY][curX-1]!='X') {
            visit[curY][curX-1] = true;
            q.push(make_pair(curY, curX-1));
        }
        if(curX+1<(*maps)[0].size()&&!visit[curY][curX+1]&&(*maps)[curY][curX+1]!='X') {
            visit[curY][curX+1] = true;
            q.push(make_pair(curY, curX+1));
        }
        
        
    }

    return sum;
}
    

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    bool visit[101][101];
    fill(&visit[0][0], &visit[100][101], false);
    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[i].size(); j++) {
            if(!visit[i][j]&&maps[i][j]!='X') {
                answer.push_back(BFS(i,j,&maps,visit));
            }
        }
    }
    
    if(answer.size()!=0)
        sort(answer.begin(), answer.end());
    else
        answer.push_back(-1);

    return answer;
}
