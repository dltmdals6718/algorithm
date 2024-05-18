import java.util.*;
class Solution {
    
    class Job {
        int requestTime; // 요청 시각
        int needTime; // 소요 시간
        
        public Job(int requestTime, int needTime) {
            this.requestTime = requestTime;
            this.needTime = needTime;
        }
    }
    
    public int solution(int[][] jobs) {
        int answer = 0; // 각 작업이 요청부터 종료까지 걸린 시간 (아직 평균은 안냈음)
        
        // 요청 오름차순
        Arrays.sort(jobs, (o1, o2) -> {
            if(o1[0] == o2[0])
                return o1[1] - o2[1];
            return o1[0] - o2[0];
        });
        
        // 우선순위 큐 : 소요시간이 작은게 먼저 나옴. 수행해야할 작업 목록
        PriorityQueue<Job> pq = new PriorityQueue<>((o1, o2) -> {
            return o1.needTime - o2.needTime;
        });
        
        // 수행할 작업
        int idx = 0;
        while(idx < jobs.length) {
            
            pq.add(new Job(jobs[idx][0], jobs[idx][1])); // 첫번째 작업 수행
            int curTime = jobs[idx][0]; // 현재 시각
            
            // 첫번째 작업을 수행하며 들어온 작업들 확인
            idx++;
            while(pq.size() != 0) {
                Job job = pq.poll();
                answer += (job.needTime + curTime) - job.requestTime; // 작업 처리 시간
                curTime += job.needTime; // 현재 시간은 작업 소요 시간을 더해줌

                // 현재 시간 이내 다른 작업이 들어올 수 있는지 확인
                while(idx < jobs.length && jobs[idx][0] <= curTime) {
                    pq.add(new Job(jobs[idx][0], jobs[idx][1]));
                    idx++;
                }
            }
        }
        
        answer /= jobs.length;
        return answer;
    }
}
