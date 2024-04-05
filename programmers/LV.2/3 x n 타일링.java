import java.util.*;
class Solution {
    public long solution(int n) {
        long answer = 0;
        
        long dp[] = new long[5001];
        dp[1] = 0L;
        dp[2] = 3L;
        
        for(int i=4; i<=n; i++) {
            if(i%2==0) {
                long sum = 0L;
                sum += (dp[i-2] * 3) % 1000000007;
                for(int j=i-4; j>=2; j-=2) {
                    sum += (dp[j] * 2) % 1000000007;
                }
                sum += 2;
                dp[i] = sum % 1000000007;
            }
        }
        
        answer = dp[n] % 1000000007;
        
        return answer;
    }
}
