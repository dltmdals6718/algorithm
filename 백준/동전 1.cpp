#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin>>N>>K;
    
    int arr[101];
    for (int i=0; i<N; i++) {
        cin>>arr[i];
    }
    
    int dp[10001];
    fill(&dp[0], &dp[10001], 0);

    // N원을 가지고 K원을 만들고 싶다면 dp[K] = dp[K] + dp[K-N];
    dp[0] = 1;
    for (int i=0; i<N; i++) {
        for (int j=arr[i]; j<=K; j++) {
            dp[j] += dp[j - arr[i]];
        }
    }
    
    cout<<dp[K];
}
