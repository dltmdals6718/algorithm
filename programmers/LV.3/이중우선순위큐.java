import java.util.*;
class Solution {
    
    public Integer getExistKey(Map<Integer, Integer> m, PriorityQueue<Integer> pq) {
        while(true) {
            Integer key = pq.poll();
            Integer value = m.getOrDefault(key, 0);
            
            // 뽑을 키가 없으면
            if(key == null)
                return null;
            
            // 
            if(value>0)
                return key;
        }
    }
    
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        
        // 최소, 최대 힙 선언
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        // 값이 남아 존재하는지 확인하는 Map
        Map<Integer, Integer> m = new HashMap<>();
        
        // 배열 operations에서 i번쨰 원소는 get(i)가 아닌 [i]임.
        for(int i=0; i<operations.length; i++) {
            String[] str = operations[i].split(" ");
            if(str[0].equals("I")) {
                
                // Integer.parseInt(), Integer.valueOf()
                Integer value = Integer.valueOf(str[1]);
                
                minHeap.add(value);
                maxHeap.add(value);
                if(m.get(value) == null)
                    m.put(value, 1);
                else
                    m.put(value, m.get(value) + 1);   
            } else {

                if(str[1].equals("-1")) {
                    Integer key = getExistKey(m, minHeap);
                    Integer value = m.getOrDefault(key, 0);
                    if(key!=null && value>0) {
                        m.put(key, value-1);
                    }
                } else {
                    Integer key = getExistKey(m, maxHeap);
                    Integer value = m.getOrDefault(key, 0);
                    if(key!=null && value>0) {
                        m.put(key, value-1);
                    }
                }
            }
        }
        
        Integer maxKey = getExistKey(m, maxHeap);
        Integer maxValue = m.getOrDefault(maxKey, 0);
        if(maxKey!=null && maxValue>0)
            answer[0] = maxKey;
        else
            answer[0] = 0;
        
        Integer minKey = getExistKey(m, minHeap);
        Integer minValue = m.getOrDefault(minKey, 0);
        if(minKey!=null && minValue>0)
            answer[1] = minKey;
        else
            answer[1] = 0;
        
        return answer;
    }
}
