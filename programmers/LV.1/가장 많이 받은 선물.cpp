#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> m; // key: A B, value : A가 B에게 보낸 선물 개수
    map<string, int> sendCnt; // string이 보낸 선물 개수
    map<string, int> receiveCnt; // string이 받은 선물 개수
    
    for(int i=0; i<gifts.size(); i++) {
        
        int pos = gifts[i].find(" ");
        string sender = gifts[i].substr(0, pos);
        string receiver = gifts[i].substr(pos+1);
        
        sendCnt[sender]++; // 선물 보낸 개수 카운트
        receiveCnt[receiver]++; // 선물 받은 개수 카운트
        
        if (m.find(gifts[i]) == m.end()) { // A가 B에게 선물 보낸적이 없으면 1로 갱신
            m.insert({gifts[i], 1});
        } else { // A가 B에게 보낸 선물 추가
            m[gifts[i]]++;
        }
        
    }
    
    map<string, int> month; // 다음달 string이 받게 되는 선물 개수
    for(int i=0; i<friends.size(); i++) {
        for(int j=i+1; j<friends.size(); j++) { 
            string ij = friends[i] + " " + friends[j]; // A B -> i j
            string ji = friends[j] + " " + friends[i]; // B A -> j i
            
            if (m[ij]==m[ji]) { // 주고 받은 개수가 같음.
                
                int iGiftScore = sendCnt[friends[i]] - receiveCnt[friends[i]];
                int jGiftScore = sendCnt[friends[j]] - receiveCnt[friends[j]];
                
                if (iGiftScore > jGiftScore) { // i가 선물 지수 더 큼
                    month[friends[i]]++;
                    answer = max(answer, month[friends[i]]); // 정답 갱신
                } else if (iGiftScore < jGiftScore) {
                    month[friends[j]]++;
                    answer = max(answer, month[friends[j]]);
                }
                
            } else {
                if (m[ij]<m[ji]) {  // j가 i에게 더 많이 줌
                    month[friends[j]]++; // 담달에 j가 선물 하나 받음
                    answer = max(answer, month[friends[j]]);
                } else { // i가 j에게 더 많이 줌
                    month[friends[i]]++;
                    answer = max(answer, month[friends[i]]);
                }
                    
            }
            
            
        }
    }
    
    
    return answer;
}
