import java.util.*;
class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        
        Set<String> kind = new HashSet<String>();
        for(int i=0; i<gems.length; i++) {
            kind.add(gems[i]);
        }
        
        int start = 0;
        int len = 100001;
        Map<String, Integer> m = new HashMap<>(); // (보석 명, 개수)
        for(int end = 0; end<gems.length; end++) {
            
            if(m.get(gems[end]) == null) {
                m.put(gems[end], 1);
            } else {
                m.put(gems[end], m.get(gems[end])+1);
            }
            
            // start 위치의 보석이 2개 이상 포함되어 있다면 start 위치의 보석을 빼고 한칸 오른쪽으로 이동이 가능함
            // 이동해도 모든 보석을 포함하며 길이가 최소가 될 수 있기 때문임
            while(m.get(gems[start]) > 1) {
                m.put(gems[start], m.get(gems[start])-1);
                start++;
            }
            
            // 모든 종류를 포함하고 있으며 길이가 최소로 갱신할 수 있다면
            if(m.size() == kind.size() && (end - start + 1) < len) {
                answer[0] = start+1;
                answer[1] = end+1;
                len = end - start + 1;
            }
        }
        
        return answer;
    }
}
