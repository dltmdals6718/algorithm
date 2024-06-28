import java.util.*;
class Solution {
    
    class Node {
        int num;
        
        Node(int num) {
            this.num = num;
        }
    }
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        int[] dis = new int[n+1]; // 부대로부터 특정 지역까지 거리
        Arrays.fill(dis, 100001); // 최대 거리는 100000이라 도달 불가능한 거리를 100001로 설정
        dis[destination] = 0; // 부대에서 부대까지 거리는 0
        
        List<Integer>[] arr = new ArrayList[n+1];
        for(int i=1; i<=n; i++) {
            arr[i] = new ArrayList<>();
        }
        
        for(int i=0; i<roads.length; i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            arr[a].add(b);
            arr[b].add(a);
        }
        
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(destination));
        while(q.size() != 0) {
            Node node = q.poll();
            int cur = node.num;
            
            for(int i=0; i<arr[cur].size(); i++) {
                int next = arr[cur].get(i);
                if(dis[next] == 100001) { // 처음 방문하는 지역이라면
                    dis[next] = dis[cur] + 1; // 현재 지역까지의 거리 +1로 갱신. BFS라 항상 첫 방문이 최소 거리가 된다.
                    q.offer(new Node(next));
                }
            }
            
        }
        
        for(int i=0; i<sources.length; i++) {
            int start = sources[i];
            if(dis[start] == 100001) // 도달 불가능한 지역이라면
                answer[i] = -1;
            else
                answer[i] = dis[sources[i]];
        }
        
        return answer;
    }
}
