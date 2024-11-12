#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stack;
    
    for(int i=0; i<s.length(); i++) {
        
        if (s[i] == '(')
            stack.push(s[i]);
        else {
            
            if (stack.empty()) { // 닫는 괄호가 있는데 여는 괄호가 없다면
                answer = false;
                break;
            } else {
                stack.pop();
            }
            
        }
        
    }
    
    if (stack.size() > 0) // 여는 괄호가 남아있다면
        answer = false;

    return answer;
}
