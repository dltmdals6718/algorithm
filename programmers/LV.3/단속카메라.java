import java.util.*;
class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        Arrays.sort(routes, (o1, o2) -> {
            return o1[1] - o2[1];
        });

        int end = routes[0][1]; // 진출 지점에 카메라 설치
        answer++;
    
        for(int i=1; i<routes.length; i++) {
            if(end < routes[i][0]) { // 다음 자동차의 진입이 현재 카메라 위치보다 크다면 새로운 카메라가 필요함.
                end = routes[i][1];
                answer++;
            }
        }
        
        return answer;
    }
}
