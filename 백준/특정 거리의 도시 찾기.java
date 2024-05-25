import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = (reader.readLine()).split(" ");
        int N = Integer.parseInt(inputs[0]);
        int M = Integer.parseInt(inputs[1]);        
        int K = Integer.parseInt(inputs[2]);
        int X = Integer.parseInt(inputs[3]);
        
        List<Integer>[] arr = new ArrayList[N+1];
        for(int i=0; i<arr.length; i++) {
            arr[i] = new ArrayList<Integer>();
        }
        
        for(int i=0; i<M; i++) {
            String[] str = reader.readLine().split(" ");
            int A = Integer.parseInt(str[0]);
            int B = Integer.parseInt(str[1]);
            arr[A].add(B);   
        }
        
        int[] dis = new int[N+1];
        Arrays.fill(dis, -1);
        List<Integer> answer = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        q.offer(X);
        dis[X] = 0;
        
        while(q.size() != 0) {
            int cur = q.poll();
            
            if(dis[cur] == K)
                answer.add(cur);     
            
            for(int i=0; i<arr[cur].size(); i++) {
                if( arr[cur].get(i) != X && dis[arr[cur].get(i)] == -1) {
                    q.offer(arr[cur].get(i));
                    dis[arr[cur].get(i)] = dis[cur] + 1;
                }
            }
        }
        
        if(answer.size() == 0) {
            System.out.print("-1");
        } else {
            answer.sort((o1, o2) -> {
                return o1 - o2;
            });
            
            for(int i=0; i<answer.size(); i++) {
                    System.out.println(answer.get(i));
            }
        }
        
        
    }
}
