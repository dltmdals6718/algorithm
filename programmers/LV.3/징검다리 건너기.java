class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0;
        
        int start = 0;
        int end = 200000000;
        
        while(start<=end) {
            int mid = (start + end) / 2;
            if(isAble(stones, k, mid)) {
                answer = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return answer;
    }
    
    // stones를 n명이 건널 수 있는가
    boolean isAble(int[] stones, int k, int n) {
        
        int cnt = 0;
        for(int i=0; i<stones.length; i++) {
            if(stones[i] < n)
                cnt++;
            else
                cnt=0;
            
            if(cnt==k)
                return false;
        }
        return true;
    }
}
