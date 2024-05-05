
class Solution {
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        int way[][] = new int[101][101];
        
        for(int i=0; i<puddles.length; i++) {
            way[puddles[i][1]][puddles[i][0]] = -1;
        }
    
        way[1][1] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                
                if(way[i][j] == -1)
                    continue;
                
                if(j-1>=0 && way[i][j-1] != -1) {
                    way[i][j] += way[i][j-1];
                    way[i][j] %= 1000000007;
                }
                
                if(i-1>=0 && way[i-1][j] != -1) {
                    way[i][j] += way[i-1][j];
                    way[i][j] %= 1000000007;
                }
            }
        }
        
        answer = way[n][m];
        return answer;
    }
}
