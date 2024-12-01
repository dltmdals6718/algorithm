#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    //  1  2  3  4  5
    // [1, 2, 3, 2, 3]	
    // [4, 3, 1, 1, 0]
    
    int arr[100001];
    fill(&arr[0], &arr[100001], 0);
    stack<pair<int, int>> s; // <값, 인덳>
    for (int i=0; i<prices.size(); i++) {
        
        while (s.size() != 0 && s.top().first > prices[i]) {
            int idx = s.top().second;
            arr[idx]= i - idx;
            s.pop();
        }
        
        s.push(make_pair(prices[i], i));
        
    }
    
    while (!s.empty()) {
        int idx = s.top().second;
        arr[idx] = (prices.size() - 1) - idx;
        s.pop();
    }
    
    for (int i=0; i<prices.size(); i++)
        answer.push_back(arr[i]);
    

    
    return answer;
}
