#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long int leftSum = 0; // 왼쪽 큐(queue1)의 총 합
    long long int rightSum = 0;
    for(int i=0; i<queue1.size(); i++) {
        leftSum+=queue1[i];
        rightSum+=queue2[i];
    }
    
    int max = queue1.size();
    
    if((leftSum+rightSum)%2!=0) // 짝수가 아니라면 둘로 절대 둘로 나눌 수 없다.
        return -1;
    
    long long int target = (leftSum+rightSum)/2; // 목표 값은 총합의 절반
    int leftIdx=0; // vector의 erase 사용시 다시 앞으로 하나씩 옮기는데 O(n)이 걸리기에
    int rightIdx=0; // 인덱스를 사용하여 큐를 구현함 (erase 사용시 시간초과 발생)
    while(1) {
        if(leftSum==rightSum) // 두 큐가 같은 총합을 가질때
            break;
        else if(answer>=max*3) // 왼쪽 큐가 오른쪽 큐로 모두 갔다가(1) + 오른쪽 큐(왼쪽 큐가 쌓여있는 상황)를 모두 왼쪽큐로 갔을때(2) = (1+2) 모든 경우를 해본 상태임으로 더이상 방법 존재하지 않음
            return -1;
        
        if(leftSum>rightSum&&queue1.size()>0) { // 왼쪽 큐에서 오른쪽 큐로 수를 하나 옮김
            rightSum+=queue1[leftIdx];
            leftSum-=queue1[leftIdx];
            queue2.push_back(queue1[leftIdx]);
            leftIdx++; // 왼쪽 큐의 첫번째 수의 인덱스 증가
            answer++;
        } else if(leftSum<rightSum&&queue2.size()>0){ // 오른쪽 큐 -> 왼쪽
            leftSum+=queue2[rightIdx];
            rightSum-=queue2[rightIdx];
            queue1.push_back(queue2[rightIdx]);
            rightIdx++;
            answer++;
        }
    }
    
    
    return answer;
}
