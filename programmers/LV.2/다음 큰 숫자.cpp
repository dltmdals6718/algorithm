#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string convert(int n) {
    
    string str = "";
    while (n > 0) {
        str += to_string(n % 2);
        n /= 2;
    }

    reverse(str.begin(), str.end());
    return str;
}

int countNumberOne(string str) {
    int cnt = 0;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '1') {
            cnt++;
        }
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int num = n+1;
    while(1) {
        
        if (countNumberOne(convert(n)) == countNumberOne(convert(num))) {
            answer = num;
            break;
        } else {
            num++;
        }
        
    }
    
    
    return answer;
}
