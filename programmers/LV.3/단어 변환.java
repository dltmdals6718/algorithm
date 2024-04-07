import java.util.*;
class Solution {
    
    class Pair {
        String word;
        int cnt;
        
        public Pair(String word, int cnt) {
            this.word = word;
            this.cnt = cnt;
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        int cost[] = new int[50];
        for(int i=0; i<50; i++)
            cost[i] = 9876;
        Queue<Pair> q = new LinkedList<>();
        
        q.add(new Pair(begin, 0));
        
        // Queue에는 empty()가 없고 size()를 써야함...
        while(q.size() != 0) {
            
            String word = q.peek().word;
            int cnt = q.peek().cnt;
            q.remove();
            
            for(int i=0; i<words.length; i++) {
                int diff = 0; // 차이나는 글자수
                
                // 충격. 배열은 필드 length이지만 String에서는 메서드 length()임.
                for(int j=0; j<words[i].length(); j++) {   
                    // 또 다시 충격.. String str = "abc"일때 str[0]은 못함 str.charAt(0) 써야함.!
                    if(words[i].charAt(j) != word.charAt(j))
                        diff++;
                }
                
                // 글자 수 차이가 1이고, 비용이 더 싸게 진입 가능하다면
                if(diff == 1 && cnt+1 < cost[i]) {
                    cost[i] = cnt+1;
                    q.add(new Pair(words[i], cnt+1));
                }
                
                
            }
            
        }
        
        // words에 target이 존재하면 answer 갱신
        for(int i=0; i<words.length; i++) {
            if(target.equals(words[i]))
                answer = cost[i];
        }
        
        return answer;
    }
    
    // Queue, length, length(), C++ pair<> -> 클래스 만들어 사용하기, charAt
    // Stack에서는 push(), pop() 이였지만 Queue에서는 add(), remove()
}
