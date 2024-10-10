#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    int N;
    cin>>N;
    
    int dp[1000001];
    fill(&dp[0], &dp[1000001], 1000001);
    
    dp[N] = 0;
    for (int i=N; i>=1; i--) {
        
        if (i % 3 == 0) {
            dp[i/3] = min(dp[i/3], dp[i] + 1);
        }
        
        if (i % 2 == 0) {
            dp[i/2] = min(dp[i/2], dp[i] + 1);
        }
        
        if (i - 1 >= 0) {
            dp[i-1] = min(dp[i-1], dp[i] + 1);
        }
        
    }
    
    cout<<dp[1];
    
    
    
}
