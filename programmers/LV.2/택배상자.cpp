#include <string>
#include <vector>

#include <iostream>
#include <queue>
#include <stack>

using namespace std;


int solution(vector<int> order) {
    int answer = 0;
    
    queue<int> belt;
    stack<int> subBelt;
    for (int i=1; i<=order.size(); i++)
        belt.push(i);
    
    int idx = 0;
    while(idx < order.size()) {
    
        
        
        if (belt.size() > 0 && belt.front() == order[idx]) {
            belt.pop();
            answer++;
            idx++;
        } else if (subBelt.size() > 0 && subBelt.top() == order[idx]) {
            subBelt.pop();
            answer++;
            idx++;
        } else if (belt.size() > 0) {
            subBelt.push(belt.front());
            belt.pop();
        } else {
            break;
        }
        
    }
    
    
    return answer;
}
