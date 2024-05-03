class Solution {
    public int[] solution(int n, int s) {
        int[] answer = null;
        

        if(n>s) { // n:2 s:1과 같은 경우 집합을 채울 수 없음.
            answer = new int[1];
            answer[0] = -1;
        } else { // 집합을 1로 다 채우고 남은 원소를 채우면 되니깐 어떻게든 가능함.
            int[] arr = new int[n];
            
            // 채울 집합의 인덱스
            int idx = 0;
            while(n!=0) {
                arr[idx] = s/n;
                s -= arr[idx];
                n--;
                idx++;
            }
            
            answer = arr;
        }
        return answer;
    }
}
