#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> stack;
    
    for(int i=0; i<s.length(); i++) {
        if(stack.size() == 0)
            stack.push(s[i]);
        else {
            if(stack.top() == s[i])
                stack.pop();
            else
                stack.push(s[i]);
        }
    }
    
    if (stack.size() == 0)
        answer = 1;
    

    return answer;
}
