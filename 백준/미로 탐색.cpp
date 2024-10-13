#include <iostream>
#include <string>
#include <queue>
using namespace std;

void sol(vector<vector<int>> v) {
    
    
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(1, make_pair(0, 0)));

    
    
    bool visit[v.size()][v[0].size()];
    fill(&visit[0][0], &visit[v.size()-1][v[0].size()], false);
    visit[0][0] = true;    
    
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        
        int cnt = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        
        if (y == v.size()-1 && x == v[0].size()-1) {
            cout<<cnt;
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            
            if (ny>=0 && ny < v.size() && nx>=0 && nx<v[0].size() && visit[ny][nx] == false && v[ny][nx] == 1) {
                visit[ny][nx] = true;
                q.push(make_pair(cnt+1, make_pair(ny, nx)));
            }
            
        }
        
        
    }
    
    
    
    
}

int main() {
    
    int N, M;
    cin>>N>>M;
    
    vector<vector<int>> v;
    for (int i=0; i<N; i++) {
        string str;
        cin>>str;
        vector<int> arr;
        for (int j=0; j<M; j++) {
            arr.push_back(str[j] - '0');
        }
        v.push_back(arr);
    }
    
    sol(v);
}
