#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    
    while (b!=0) {
        int r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int solution(vector<int> arr) {
    int answer = 1;

    
    for (int i=0; i<arr.size(); i++) {
        answer = (answer * arr[i])/gcd(answer, arr[i]);
    }
    
    return answer;
}
