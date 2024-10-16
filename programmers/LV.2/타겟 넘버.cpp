#include <string>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int idx, int n, int sum, int target, vector<int> &v, int &answer) {
    
    if (idx == n) {
        if (sum == target)
            answer++;
        return;
    }
    
    dfs(idx+1, n, sum+v[idx], target, v, answer);
    dfs(idx+1, n, sum-v[idx], target, v, answer);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, numbers.size(), 0, target, numbers, answer);
    
    return answer;
}
