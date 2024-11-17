#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int eraseCnt = 0;
    int convertCnt = 0;
    while(s != "1") {
        
        convertCnt++;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '0') {
                eraseCnt++;
                s.erase(s.begin() + i);
                i--;
            }
        }
        
        string expression = "";
        int len = s.length();
        while(len > 0) {
            expression += to_string(len % 2);
            len /= 2;
        }
        
        reverse(expression.begin(), expression.end());
        s = expression;
    }
    
    
    answer.push_back(convertCnt);
    answer.push_back(eraseCnt);
    
    return answer;
}
