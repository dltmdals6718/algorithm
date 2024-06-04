import java.util.*;
class Solution {
    public int solution(int n, int[][] costs) {
        int answer = 0;
        Arrays.sort(costs, (o1, o2) -> {
            return o1[2] - o2[2];
        });
        
        int parent[] = new int[101];
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
        
        for(int i=0; i<costs.length; i++) {
            if(find(costs[i][0], parent) != find(costs[i][1], parent)) {
                union(costs[i][0], costs[i][1], parent);
                answer += costs[i][2];
            }
        }
        
        return answer;
    }
    
    public void union(int a, int b, int parent[]) {
        int aParent = find(a, parent);
        int bParent = find(b, parent);
        if(aParent != bParent) {
            parent[aParent] = bParent;
        }
    }
    
    public int find(int i, int parent[]) {
        if(parent[i] == i) {
            return i;
        } else {
            return find(parent[i], parent);
        }
    }
    
}
