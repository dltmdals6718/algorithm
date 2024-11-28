#include <string>
#include <vector>
#include <iostream>
using namespace std;


long long fibo(int n, long long (&dp)[2001]) {

    if (n < 0)
        return 0;
    else if (dp[n] !=0)
        return dp[n];
    
    dp[n] = (fibo(n-1, dp) % 1234567 + fibo(n-2, dp) % 1234567) % 1234567;
    return dp[n];
}


long long solution(int n) {
    long long answer = 0;
    
    long long dp[2001];
    fill(dp, dp+2001, 0);
    
    dp[0] = 1;
    dp[1] = 1;
    answer = fibo(n, dp) % 1234567;
    
    for(int i=0; i<=n; i++)
        cout<<dp[i]<<" ";
    return answer;
}
