#include <iostream>
#include <string>
using namespace std;
int main() {
    
    int dp[11];
    fill(&dp[0], &dp[11], 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4; // => 1 1 1 / 1 2 / 2 1 / 3
    
    for (int i=4; i<=10; i++) {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }
    
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        cout<<dp[n]<<endl;       
    }
    
}
