#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    // x^2+y^2=r^2
    for(long long i=1; i<=r2; i++) {
        
        // 원 r1의 밖 영역은 r1의 y를 0으로 가정해야 0부터 r2의 y 까지 정수를 구할 수 있다.
        int r1y = 0;
        if(i<=r1) {
            r1y = ceil(sqrt((((long long)r1*r1)-(i*i))));
        }
        
        int r2y = floor(sqrt((((long long)r2*r2)-(i*i))));
        answer+=(r2y-r1y+1);
    }
    
    // r1 ceil, r2 floor 하는 이유 : r1보다 크거나 같고 r2보다 작거나 같은 구간의 정수를 구해야하기 때문에 r1을 올림, r2는 내림으로 사이의 정수를 구한다.
                        
    answer *= 4;
    return answer;
}
