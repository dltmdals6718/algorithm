import java.util.*;
class Solution {
    
    public void dfs(int[][] computers, boolean visit[], int idx) {
        Stack<Integer> s = new Stack<>();
        s.push(idx);
        
        while(!s.empty()) {
            int cur = s.peek();
            s.pop();
            
            for(int i=0; i<computers[cur].length; i++) {
                if(!visit[i] && computers[cur][i] == 1) {
                    visit[i] = true;
                    s.push(i);
                }
            }
        }
        
        
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean visit[] = new boolean[200];
        
        for(int i=0; i<n; i++) {
            if(!visit[i]) {
                answer++;
                visit[i] = true;
                dfs(computers, visit, i);
            }
        }
        return answer;
    }
}
