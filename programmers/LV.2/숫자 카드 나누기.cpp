#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    int temp;
    while(b!=0) {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    
    // 길이는 최소 1이라 0번째 값을 최대 공약수로 설정
    int chulSu = arrayA[0];
    int youngHee = arrayB[0];
    
    // A와 B의 길이는 동일하다.
    // A와 B의 최대 공약수 구하기.
    for(int i=1; i<arrayA.size(); i++) {
        chulSu = gcd(chulSu, arrayA[i]);
        youngHee = gcd(youngHee, arrayB[i]);
    }
    
    // A(chulSu): chulSu의 최대 공약수로 youngHee 카드를 모두 나눌 수 있는가?
    // B는 영희의 최대 공약수로 철수 카드들을 모두 나눌 수 있는가?
    bool A = true; // 초기값 : 가능(true)
    bool B = true;
    for(int i=0; i<arrayA.size(); i++) {
        if (A&&arrayB[i]%chulSu==0) { // A가 현재 가능 상태이고 chulSu(A)것으로 영희의 i번째 나눠진다면
            A=false; // A(chulSu의 최대 공약수)는 정답이 될 수 없으므로 false 처리.
        }
        if (B&&arrayA[i]%youngHee==0) {
            B=false;
        }
    }
    
    if(A) { // A가 참이라면 chulSu의 최대 공약수로 영희 카드들을 모두 나눌 수 없는것
        answer = chulSu;
    }
    
    if(B) { // B가 참이라면 youngHee의 최대 공약수로 철수 카드들을 모두 나눌 수 없는것
        answer = max(answer, youngHee);
    }
    
    return answer;
}
