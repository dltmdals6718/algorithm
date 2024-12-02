#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // 1 2 3 4
    while ((a/2) + (a%2) != (b/2) + (b%2)) {
        
        answer++;
        
        a = (a/2) + (a%2);
        b = (b/2) + (b%2);
        
    }
    
    

    return answer;
}
