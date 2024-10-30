#include <string>
#include <map>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    map<string, bool> m;
    int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0, -1}};
    
    int x = 0;
    int y = 0;
    for (int i=0; i<dirs.length(); i++) {
        
        int ny, nx;
        
        if (dirs[i] == 'U') {
            ny = y + dir[0][0];
            nx = x + dir[0][1];
        } else if (dirs[i] == 'D') {
            ny = y + dir[1][0];
            nx = x + dir[1][1];
        } else if (dirs[i] == 'R') {
            ny = y + dir[2][0];
            nx = x + dir[2][1];
        } else {
            ny = y + dir[3][0];
            nx = x + dir[3][1];
        }
        
        if (ny>= -5 && ny<=5 && nx>=-5 && nx<=5) {
            
            string cur = to_string(y) + to_string(x);
            string next = to_string(ny) + to_string(nx);
            if (m.find(cur + next) == m.end() && m.find(next + cur) == m.end()) {
                answer++;
                m.insert({cur + next, true});
                m.insert({next + cur, true});
            }
            
            y = ny;
            x = nx;
        }
        
    }
    
    return answer;
}
