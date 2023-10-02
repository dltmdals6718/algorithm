#include <string>
#include <vector>
using namespace std;

void rec(int idx, int cnt, int sum, vector<int>& number, int& answer, int maxSize) {
    if(cnt==3&&sum==0) {
        answer++;
        return;
    }
    
    for(int i=idx+1; i<maxSize; i++) {
        rec(i, cnt+1, sum+number[i], number, answer, maxSize);
    }    
}

int solution(vector<int> number) {
    int answer = 0;
    for(int i=0; i<number.size(); i++) {
        rec(i, 1, number[i], number, answer, number.size());
    }
    
    return answer;
}
