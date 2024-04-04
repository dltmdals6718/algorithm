#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    if(a[1]<=b[1])
        return true;
    else
        return false;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), comp);
    int e = 0;
    for(int i=0; i<targets.size(); i++) {
        if(targets[i][0] >= e) {
            e = targets[i][1];
            answer++;
        }
    }
    
    return answer;
}
