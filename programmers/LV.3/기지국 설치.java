import java.util.*;
class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        
        for(int i=0; i<stations.length; i++) {
            
            int len = 0;
            if(i == 0) {
                len = stations[i]-w-1;
            } else {
                len = (stations[i]-w-1) - (stations[i-1]+w+1) + 1; // i-1 기지국과 i 기지국 사이의 비전파 거리
            }
            
            if(len > 0) {
                answer += len / ((2*w)+1);
                if(len % ((2*w)+1) != 0) // 나머지가 존재하면 기지국 1개 추가해야함.
                    answer++;
            }
        }
        
        // 마지막 기지국의 오른쪽 방향 전파가 끝까지 도달하지 않는다면
        if(stations[stations.length-1]+w < n) {
            int lastRightLen = n-(stations[stations.length-1]+w);
            if(lastRightLen > 0) {
                answer += lastRightLen / ((2*w)+1);
                if(lastRightLen % ((2*w)+1) != 0)
                    answer++;
            }
        }
        

        return answer;
    }
}
