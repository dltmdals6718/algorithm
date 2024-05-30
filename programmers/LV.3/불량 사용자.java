import java.util.*;
class Solution {
    
    public void dfs(int idx, String[] user_id, String[] banned_id, boolean[] visit, Map<String, Boolean> m) {
        
        if(idx==banned_id.length) {
            String str = "";            
            for(int i=0; i<visit.length; i++) {
                if(visit[i])
                    str += "1";
                else
                    str += "0";
            }
            
            if(m.get(str) == null)
                m.put(str, true);
            return;
        }
        
        
        for(int i=0; i<user_id.length; i++) {
            if(isSame(user_id[i], banned_id[idx]) && !visit[i]) {
                visit[i] = true;
                dfs(idx+1, user_id, banned_id, visit, m);
                visit[i] = false;
            }
        }
    }
    
    
    public int solution(String[] user_id, String[] banned_id) {
        boolean[] visit = new boolean[user_id.length];
        Map<String, Boolean> m = new HashMap<>();
        dfs(0, user_id, banned_id, visit, m);
        return m.size();
    }
    
    public boolean isSame(String userId, String bannedId) {
        
        if(userId.length() != bannedId.length())
            return false;
        
        for(int i=0; i<userId.length(); i++) {
            if(bannedId.charAt(i) != '*' && userId.charAt(i) != bannedId.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}
