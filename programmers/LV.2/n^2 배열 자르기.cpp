#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    
    
    //   1 2 3
    // 1 1 2 3
    // 2 2 2 3
    // 3 3 3 3
    
    // i행과 j열중 더 큰 값으로 초기화 됨
    
    vector<int> answer;
    
    // left는 몇행 몇열?
    // 행 : left / n, 열 : left % n
    
    while (left <= right) {
        int row = left / n;
        int col = left % n;
        
        answer.push_back(max(row, col) + 1);
        left++;
    }
    
    
    return answer;
}
