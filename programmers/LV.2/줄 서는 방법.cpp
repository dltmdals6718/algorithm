#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long int factorial(int n) {
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> number;
    
    // 1~n 번호 삽입
    for(int i=1; i<=n; i++) {
        number.push_back(i);
    }
    
    
    // 문제에서 주어진 k는 1~k번째 인덱스를 가지지만. 실제 number 배열은 0~k-1의 인덱스를 가짐
    // 그래서 k-1로 실제 배열과 인덱스를 맞춘다.
    k--;
    while(n>1) {
        // n이 1일때 factorial 계산이 안되므로 탈출
        // sameArea: 첫번째 번호가 동일한 집합의 크기
        long long int sameArea = factorial(n-1);
        
        // index: 첫번째 번호의 인덱스
        int index = k/sameArea;
        
        // k: 현재 찾아야할 k번째 방법
        k%=sameArea;
        n--;
        answer.push_back(number[index]);
        number.erase(number.begin()+index);
    }

    //n이 1일때 위의 while문에서 계산이 안되었으므로 남은 0번째 번호를 삽입
    answer.push_back(number[0]);
    
    
    return answer;
}
