#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (long long x = 0; x <= d; x += k) {
        // d^2 = x^2 + y^2
        // y = sqrt(d^2-x^2)
        int maxY = sqrt((long long)d*d-(long long)x*x);
        answer += (maxY / k) + 1;
        // +1 이유 : y가 6일때 k는 2라면 6/2는 3이다.
        // (x, 2), (x, 4), (x, 6)에 (x, 0)을 추가했기에 +1을 해준것.
        
        // x는 0부터 k배수로 증가하여 d이하일때까지 반복.
        // 이때 구해지는 최대값 y에서 가능한 k배수의 개수를 구한다. (y/k)
        // 이때 0은 포함되지 않으므로 +1을 해준다.
    }

    
    return answer;
}
