import java.util.*;
class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i=0; i<works.length; i++) {
            pq.add(works[i]);
        }
        
        while(n>0) {
            Integer work = pq.poll();
            if(work>0) {
                pq.add(work-1);
            } else {
                break;
            }
            n--;
        }
        
        while(pq.size() > 0) {
            Integer a = pq.poll();
            answer += a*a;
        }
        
        return answer;
    }
}
