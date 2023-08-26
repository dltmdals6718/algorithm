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
    for(int i=1; i<=n; i++) {
        number.push_back(i);
    }
    
    
    k--;
    while(n>1) {
        long long int sameArea = factorial(n-1);
        int index = k/sameArea;
        k%=sameArea;
        n--;
        answer.push_back(number[index]);
        number.erase(number.begin()+index);
    }

    answer.push_back(number[0]);
    
    
    return answer;
}
