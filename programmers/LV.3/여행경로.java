import java.util.*;
class Solution {
    
    public String[] solution(String[][] tickets) {
        String[] answer;
        
        List<String> pathList = new ArrayList<>();
        boolean[] visit = new boolean[tickets.length];
        dfs(tickets.length, "ICN", "ICN", pathList, visit, tickets);
        
        pathList.sort((o1, o2) -> {
            return o1.compareTo(o2);
        });
        
        answer = pathList.get(0).split(",");
    
        return answer;
    }
    
    void dfs(int leaveTicket, String cur, String path, List<String>pathList, boolean[] visit, String[][] tickets) {
        if(leaveTicket == 0) {
            pathList.add(path);
            return;
        }
        
        for(int i=0; i<tickets.length; i++) {
            String ticketStart = tickets[i][0]; // 티켓의 출발지
            String ticketGoal = tickets[i][1]; // 티켓의 목적지
            
            if(ticketStart.equals(cur) && visit[i] == false) {
                visit[i] = true;
                dfs(leaveTicket-1, ticketGoal, path+","+ticketGoal, pathList, visit, tickets);
                visit[i] = false;
            }
        }
    }
}
