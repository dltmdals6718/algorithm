#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    
    if (a <= b)
        return true;
    else
        false;
    
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    // 최댓값과 최솟값을 곱하면 최소값이 된다. 이것을 누적하여 계산
    // A를 오름차순으로 정렬
    sort(A.begin(), A.end());

    // B를 내림차순으로 정렬
    sort(B.rbegin(), B.rend());
    
    for (int i=0; i<A.size(); i++) {
        answer += A[i] * B[i];
    }


    return answer;
}
