#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int storey) {
    int answer = 0;
    
    while(storey!=0) { // storey가 0이 될때까지
        if(storey%10<5) { // 일의 자리수가 5미만이라면 -로 빼버리는게 이득.
            answer+=storey%10; // 일의 자리수 크기만큼 -1 연산이 필요.
        } else if (storey%10==5) { // 일의 자리수가 5라면
            if((storey/10)%10>=5) // 다음 자리수가 5이상이라면
                storey+=10; // 덧셈 연산으로 +5 해버리는게 (올림) 이득
            answer+=5; // 덧셈 5번 연산 필요
        } else {
            answer+=10-(storey%10); // 일의 자리수가 6이상이라면 올림 - 10을 만들기 위한 연산횟수 필요
            storey+=10; // 올림에 의해 십의 자리에 1을 더해줌
        }
        storey/=10; // 일의 자리 제거
    }
    
    return answer;
}
