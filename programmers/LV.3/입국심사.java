import java.util.*;
class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        
        Arrays.sort(times);
        
        long left = 0;
        long right = times[times.length-1] * (long)n; 
        // "*" 연산에 long 타입이 없으면
        // 연산 결과를 int로 해석 저장하고 long으로 변환하기에 올바른 연산 결과가 아님
        // 연산 결과를 long으로 해석 저정하기 (long)n 해줘야함.
        
        while(left <= right) {
            
            long mid = (left + right) / 2;
            long cnt = 0; // 심사 받을 수 있는 사람
            for(int i=0; i<times.length; i++) {
                cnt += mid / times[i];
            }
            
            // 받을 수 있는 사람이 실제 사람 보다 작으면 시간을 더 늘려야함.
            if(cnt < n) {
                left = mid + 1;
            } else if (cnt == n) {
                answer = mid;
                break;
            } else {
                right = mid - 1;
            }
            
        }
        
        return answer;
    }
}
