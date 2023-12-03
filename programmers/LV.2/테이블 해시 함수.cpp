#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int column = 1;

bool compare(vector<int> a, vector<int> b) {
    if(a[column-1] < b[column-1]) { // col번째 컬럼의 값을 기준으로 오름차순 정렬
        return true;
    } else if(a[column-1] == b[column-1]) { // 동일하면 기본키인 첫 번째 컬럼의 값을 기준으로 내림차순 정렬
        if(a[0] > b[0]) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col; // compare 함수에서 col을 쓸 수 있도록 전역변수 사용
    sort(data.begin(), data.end(), compare);
    
    int result = -1;
    for(int i=row_begin-1; i<=row_end-1; i++) {
        int modSum = 0;
        for(int j=0; j<data[0].size(); j++)
            modSum += data[i][j]%(i+1);
        if(result==-1) // result가 -1이라면 첫 갱신이므로 modSum으로 갱신
            result=modSum;
        else
            result = result ^ modSum; // XOR 연산
    }
    
    answer=result;
    return answer;
}
