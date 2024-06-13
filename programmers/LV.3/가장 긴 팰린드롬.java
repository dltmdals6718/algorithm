import java.util.*;
class Solution
{
    public int solution(String s)
    {
        int answer = 0;
        
        for(int i=s.length(); i>=1; i--) { // 검사할 팰린드롬 길이
            
            for(int j=0; j<=s.length()-i; j++) { // 시작 위치
                int cnt = 0;
                int start = j; // 시작 위치
                int end = j+i-1; // 끝 위치
                
                boolean flag = true; // 팰린드롬 가능 여부
                while(start <= end) {
                    if(s.charAt(start) != s.charAt(end)) {
                        flag = false;
                        break;
                    }
                    start++;
                    end--;
                }
                
                // 팰린드롬 길이가 긴 것부터 탐색하므로 첫 탐색이 최대 길이임
                if(flag) {
                    return i;
                }
                    
            }
        }
        
        return answer;
    }
}
