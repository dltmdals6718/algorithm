#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<pair<int, int>> s; // (값, 위치)
    
    
    int arr[1000001];
    fill(&arr[0], &arr[1000001], -1);
    
    for (int i=0; i<numbers.size(); i++) {
        
        if (s.empty())
            s.push(make_pair(numbers[i], i));
        
        while (!s.empty() && s.top().first < numbers[i]) {
            arr[s.top().second] = numbers[i];
            s.pop();
        }
        
        s.push(make_pair(numbers[i], i));
        
    }
    
    for (int i=0; i<numbers.size(); i++)
        answer.push_back(arr[i]);
    
    
    
    return answer;
}
