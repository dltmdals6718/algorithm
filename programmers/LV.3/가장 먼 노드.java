import java.util.*;
class Solution {
    
    public class Node {
        int num; // 노드 번호
        int cost; // 1부터 이 노드까지 걸리는 비용
        
        public Node(int num, int cost) {
            this.num = num;
            this.cost = cost;
        }
    }
    
    
    public int solution(int n, int[][] edge) {
        int answer = 0;

        List<Integer>[] list = new ArrayList[n+1];
        for(int i=0; i<list.length; i++) {
            list[i] = new ArrayList<>(); 
        }
        
        // list[x]에는 노드 x에서 연결된 노드들이 리스트로 담겨있다.
        for(int i=0; i<edge.length; i++) {
            list[edge[i][0]].add(edge[i][1]);
            list[edge[i][1]].add(edge[i][0]);
        }
        
        boolean visit[] = new boolean[20001];
        Queue<Node> q = new LinkedList<Node>();
        q.add(new Node(1, 0));
        visit[1] = true;
        
        // 최대 거리
        int maxCost = 0;
        while(q.size() != 0) {
            int num = q.peek().num;
            int cost = q.peek().cost;
            q.remove();
            
            // 최대 거리랑 동일하다면 최대 거리로 갈 수 있는 노드가 더 있다는 것
            if(maxCost == cost)
                answer++;
            else { // 최대 거리와 다르다면(BFS라 최대 거리가 다르다면 항상 이전 최대거리보다 큼) 더 큰 최대 거리인 것
                answer = 1;
                maxCost = cost;
            }
            
            for(int i=0; i<list[num].size(); i++) {
                int nextNum = list[num].get(i);
                if(visit[nextNum] == false) {
                    visit[nextNum] = true;
                    q.add(new Node(nextNum, cost+1));
                }
            }
        }
        return answer;
    }
}
