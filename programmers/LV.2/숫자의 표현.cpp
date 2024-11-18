#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int start = 1;
    int end = 1;
    while(start <= (n/2)) {
        
        int sum = 0;
        for(int i=start; i<=end; i++) {
            sum += i;
        }
        
        if (sum < n) {
            end++;
        } else if (sum == n) {
            answer++;
            end++;
            start++;
        } else { // sum > n
            start++;
        }
        
    }
    
    
    return answer;
}
