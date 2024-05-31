class Solution {
    public int solution(int sticker[]) {
        int answer = 0;
        int dp[] = new int[100000]; // 첫번째 스티커를 뗀 경우
        int dp2[] = new int[100000]; // 안뗀 경우
        dp[0] = sticker[0];
        dp2[0] = 0;
        
        if(sticker.length > 1) {
            dp[1] = sticker[0];//첫번째 스티커를 뗀 경우 dp[1]은 idx 1을 뗼 수 없으니 idx 0의 값이다.
            dp2[1] = sticker[1];//첫번째 스티커를 안 뗀 경우 dp2[1]은 idx 1의 스티커를 뗀 값이 최대이다.
        } else {
            return sticker[0];
        }
            
        
        // dp[i] 위치의 값은
        // i 위치의 스티커를 뗀다면
        // i-1번째 스티커를 떼지 않은걸 뜻하는 dp[i-2] 값에 sticker[i] 값을 더한것
        // 또는
        // i 위치의 스티커를 떼지 않는다면
        // dp2[i-1]의 값이 그대로 넘어온다.
        
        for(int i=2; i<sticker.length-1; i++) {
            dp[i] = Math.max(dp[i-2] + sticker[i], dp[i-1]);
        }
        
        for(int i=2; i<sticker.length; i++) {
            dp2[i] = Math.max(dp2[i-2] + sticker[i], dp2[i-1]);
        }
        
        // sticker.length-2 < 0인 경우는 return sticker[0];에서 걸러짐
        answer = Math.max(dp[sticker.length-2], dp2[sticker.length-1]);
        return answer;
    }
}
