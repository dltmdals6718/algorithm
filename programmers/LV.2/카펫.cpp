#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // minHeight : 3, minWeight : 3
    int height = 3;
    int width = 3;
    int sum = brown + yellow;
    
    for (int height = 3; ; height++) {
        for (int width = height; ; width++) {
            
            if (height * width > sum)
                break;
            
            if (height * width == sum && (height-2)*(width-2) == yellow) {
                answer.push_back(width);
                answer.push_back(height);
                return answer;
            }
        }
    }
    
    
    return answer;
}
