import java.util.*;
class Solution {
    
    public class Info {
        
        Set<Integer> win; // 내가 이긴 사람들
        Set<Integer> lose; // 내가 진 사람들
        
        public Info() {
            this.win = new HashSet<Integer>();
            this.lose = new HashSet<Integer>();
        }
    }
    
    public Set<Integer> findChildLoser(Set<Integer> childLoser, Info[] info, int i) {
        
        for(Integer child : info[i].win) {
            
            if (!childLoser.contains(child)) {
                childLoser.add(child);
                findChildLoser(childLoser, info, child);
            }
            
        }
        return childLoser;
    }
    
    public Set<Integer> findParentWinner(Set<Integer> parentWinner, Info[] info, int i) {
        for(Integer parent : info[i].lose) {
            
            if (!parentWinner.contains(parent)) {
                parentWinner.add(parent);
                findParentWinner(parentWinner, info, parent);
            }
            
        }
        return parentWinner;
    }
    
    public void update(Info[] info) {
        
        
        // A와 B가 싸웠을때
        // A가 이겼다면 B에게 진 사람들도 A가 이긴거랑 동일함.   
        for(int i=1; i<info.length; i++) {
            
            // i에게 진 사람들 childLoser
            Set<Integer> childLoser = new HashSet<Integer>();
            findChildLoser(childLoser, info, i);
            
            // i는 childLoser들도 이긴것이다.
            for(Integer child : childLoser) {
                info[i].win.add(child);
            }
            
            // i에게 이긴 사람들 parentWinner
            Set<Integer> parentWinner = new HashSet<Integer>();
            findParentWinner(parentWinner, info, i);
            
            // i는 parentWinner에게도 진것이다.
            for(Integer parent : parentWinner) {
                info[i].lose.add(parent);
            }
            
        }
        
        
    }
    
    public int solution(int n, int[][] results) {
        int answer = 0;
        
        Info[] info = new Info[n+1];
        for(int i=1; i<=n; i++) {
            info[i] = new Info();
        }
        
        for(int i=0; i<results.length; i++) {
            
            int winner = results[i][0];
            int loser = results[i][1];
            
            info[winner].win.add(loser);
            info[loser].lose.add(winner);
            
            
        }
        
        update(info);
        
        for(int i=1; i<=n; i++) {
            System.out.println(info[i].win.size() + " " + info[i].lose.size());
            if (info[i].win.size() + info[i].lose.size() == n-1)
                answer++;
        }
        
        return answer;
    }
}
