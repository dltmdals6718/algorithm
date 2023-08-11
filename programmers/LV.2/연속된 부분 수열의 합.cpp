#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    // 비내림차순이라 항상 먼저 탐색되는게 앞쪽에 나오는 수열임
    int start = 0;
    int end = 0;
    
    int resStart = 0;
    int resEnd = 0;
    int len = 1000001;
    int sum=sequence[0];
    
    while(start<=end && end<sequence.size()) {
        if(sum<k) {
            end++;
            if(end<sequence.size()) {
                sum+=sequence[end];
            }
        } else if (sum>k) {
            sum-=sequence[start];
            start++;
        } else {
            if(end-start+1<len) {
                len = end-start+1;
                resStart = start;
                resEnd = end;
            }
            end++;
            sum+=sequence[end];
        }
    }
    answer.push_back(resStart);
    answer.push_back(resEnd);
    return answer;
}
