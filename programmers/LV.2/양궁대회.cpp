#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 라이언 과녁, 어피치 과녁
bool condition(vector<int> v, vector<int> answer) {
    
    for(int i=10; i>=0; i--) {

        if(v[i]>answer[i]) {
            return true;
        } else if(v[i]<answer[i]) {
            return false;
        }
    }
    
}


// 라이언의 과녁 상태, 쏠 과녁 번호, 남은 화살, info, answer, 현재answer의 점수차
void bruteForce(vector<int> &v, int idx, int arrow, vector<int>& info, vector<int> &answer, int* answerDiff) {
    
    // 모든 화살을 다 쏘고 과녁을 다 거쳤다면
    if(arrow==0&&idx==11) {
        
        int apeach = 0;
        int lion = 0;
        for(int i=0; i<11; i++) {
            if(v[i]==0 && info[i]==0) { // 아무도 안쏨
                continue;
            } else if (v[i] > info[i]) { // 라이언이 더 맞춤
                lion += 10-i;
            } else { // 어피치가 더 맞춤
                apeach += 10-i;
            }
        }
        
        
        int scoreDiff = lion-apeach;

        if(scoreDiff<=0) // 점수차가 음수인건 apeach가 이긴거
            return;
        
        // 점수차가 크거나 || 점수 차가 같더라도 가장 낮은 점수를 더 많이 맞힌 경우
        if((scoreDiff > *answerDiff) || ((scoreDiff == *answerDiff) && condition(v, answer))) {
            *answerDiff = scoreDiff;
            answer = v;
        }
    } else if (idx>=11) { // 화살 다 안쓰고 과녁을 다 거침
            return;
    }

    
    // 남은 화살을 idx 과녁에 0~arrow개 쏨
    for(int i=0; i<=arrow; i++) {
        v[idx] = i; // idx 과녁에 i개 쏨
        bruteForce(v, idx+1, arrow-i, info, answer, answerDiff); // idx+1 과녁에 남은 화살 쏘기
    }
    
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> v(11);
    int answerDiff = 0;

    // 쏠 화살 개수 i
    // 0번째 과녁에 i개를 쏨
    for(int i=0; i<=n; i++) {
        v[0] = i; // 0번째 과녁에 i개 화살
        bruteForce(v, 1, n-i, info, answer, &answerDiff);
    }
    
    if(answer.size()==0)
        answer.push_back(-1);
    
    return answer;
}
