#include <string>
#include <vector>
using namespace std;



void sale(vector<vector<int>> users, vector<int> emoticons, int discount[8], vector<int> &answer) {
    
    int joinCnt = 0; // 가입자 수
    int saleAmount = 0; // 판매액
    
    for(int i=0; i<users.size(); i++) {
        int buyAmount = 0; // 구매 총액

        
        for(int j=0; j<emoticons.size(); j++) {
            if(users[i][0] <= discount[j]) { // 비율 이상의 할인 이모티콘이라면 구매
                buyAmount += emoticons[j]*((double)(100-discount[j])/100);
            }
        }

        
        if(users[i][1] <= buyAmount) // 구매비용을 넘어섰기에. 이모티콘 플러스 가입
            joinCnt++;
        else // 구매 비용 내로 구매 가능
            saleAmount += buyAmount;
    }
    
    // 가입자를 늘릴 수 있거나, 가입수는 같아도 판매액을 늘릴 수 있다면 갱신
    if(answer.size() == 0 || (answer[0] < joinCnt || (answer[0] == joinCnt && answer[1] <= saleAmount))) {
        answer.clear();
        answer.push_back(joinCnt);
        answer.push_back(saleAmount);
    } 
    
}


void bruteforce(vector<vector<int>> &users, vector<int> &emoticons, int discount[8], int idx, vector<int> &answer) {
    
    // 할인율을 모두 채웠다면 판매 시뮬레이션
    if(idx==emoticons.size()) {
        sale(users, emoticons, discount, answer);
        return;
    }
    
    // 할인율 대입
    for(int i=10; i<=40; i+=10) {
        discount[idx] = i;
        bruteforce(users, emoticons, discount, idx+1, answer);
    }
    
}




vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    int discount[8];
    
    // users, emoticons, 할인율 배열, 인덱스, 답
    bruteforce(users, emoticons, discount, 0, answer);
    
    return answer;
}
