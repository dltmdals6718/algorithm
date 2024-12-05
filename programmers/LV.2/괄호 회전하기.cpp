#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string rotate(string str) {
    
    string result = "";
    for (int i=1; i<str.length(); i++) {
        result += str[i];
    }
    result += str[0];
    return result;
}

bool isRight(string str) {
    stack<char> s;
    
    for (int i=0; i<str.length(); i++) {
        
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        } else {
            
            if (s.size() == 0)
                return false;
            
            
            if (str[i] == ')' && s.top() == '(') {
                s.pop();
            } else if (str[i] == '}' && s.top() == '{') {
                s.pop();
            } else if (str[i] == ']' && s.top() == '[') {
                s.pop();
            } else {
                return false;
            }
        }
        
    }
    
    if (s.size() == 0)
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;

    for (int i=0; i<s.length(); i++) {
        if(isRight(s))
            answer++;
        s = rotate(s);
    }
    
    return answer;
}

