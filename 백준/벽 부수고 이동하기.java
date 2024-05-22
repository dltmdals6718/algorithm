import java.io.*;
import java.util.*;
public class Main {
    
    static class Pos {
        int y;
        int x;
        int z;
        int cnt;
        
        Pos(int y, int x, int z, int cnt) {
            this.y = y;
            this.x = x;
            this.z = z;
            this.cnt = cnt;
        }
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String str = reader.readLine();
        String[] nm = str.split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        int[][] map = new int[n][m];
        for(int i=0; i<n; i++) {
            String input = reader.readLine();
            for(int j=0; j<m; j++) {
                map[i][j] = input.charAt(j) - '0';
            }
        }
        int[][][] arr = new int[n][m][2];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                Arrays.fill(arr[i][j], 987654321);
            }
        }
        
        Queue<Pos> q = new LinkedList<>();
        q.offer(new Pos(0, 0, 0, 1));
        arr[0][0][0] = 1;
        
        while(q.size() != 0) {
            Pos pos = q.poll();
            int y = pos.y;
            int x = pos.x;
            int z = pos.z;
            int cnt = pos.cnt;
            int[][] dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            for(int i=0; i<4; i++) {
                int ny = y + dir[i][0];
                int nx = x + dir[i][1];
                
                if(ny>=0 && ny<n && nx>=0 && nx<m) {
                    
                    if(map[ny][nx] == 1 && z == 0 && cnt+1 < arr[ny][nx][1]) {
                        arr[ny][nx][1] = cnt+1;
                        q.offer(new Pos(ny, nx, 1, cnt+1));
                    }
                    if (map[ny][nx] == 0 && cnt+1 < arr[ny][nx][z]) {
                        arr[ny][nx][z] = cnt+1;
                        q.offer(new Pos(ny, nx, z, cnt+1));
                    }
                }
                
            }
            
        }
        
        if(arr[n-1][m-1][0] == 987654321 && arr[n-1][m-1][1] == 987654321) {
            System.out.println(-1);
        } else {
            System.out.println(Math.min(arr[n-1][m-1][0], arr[n-1][m-1][1]));
        }
    }
}
