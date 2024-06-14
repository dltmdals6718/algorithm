import java.util.*;
class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";
    
        // 분으로 변환
        List<Integer> arrive = new ArrayList<Integer>();
        for(int i=0; i<timetable.length; i++) {
            int hour = Integer.parseInt(timetable[i].charAt(0) + "" + timetable[i].charAt(1));
            int min = Integer.parseInt(timetable[i].charAt(3) + "" + timetable[i].charAt(4));
            arrive.add((hour * 60) + min);
        }
        
        // 오름차순 정렬
        arrive.sort((o1, o2) -> {
            return o1 - o2;
        });
        
        // 버스 도착 시각
        int cur = 540; // 09:00
        while(n>0) {
            
            // 탑승 가능 자리
            int space = m;
            while(space>0) {
                
                // 막차이고 1자리 남았을때
                if(n==1 && space == 1) {
                    String hour, min;
                    if(arrive.size()==0) { // 대기열이 없다면 버스 도착 시각에 탐
                        hour = String.valueOf(cur / 60);
                        min = String.valueOf(cur % 60);
                    } else {
                        if(arrive.get(0) <= cur) { // 대기중인 사람이 탑승 가능한 버스라면
                            arrive.set(0, arrive.get(0)-1); // 대기중인 사람보다 1분 일찍
                            hour = String.valueOf(arrive.get(0) / 60);
                            min = String.valueOf(arrive.get(0) % 60);
                        } else { // 대기중인 사람이 탑승 불가능하면 내가 첫번째라 버스 도착 시각에 탐
                            hour = Integer.toString(cur / 60);
                            min = String.valueOf(cur % 60);
                        }
                    }
                    
                    if(hour.length() == 1) // 1자리인경우 앞에 "0" 추가
                        hour = "0" + hour;
                    if(min.length() == 1)
                        min = "0" + min;
                    answer = hour + ":" + min;
                    break;
                }
            
                // 현재 시각 버스에 탑승 가능한 인원이라면
                if(arrive.size()>0 && arrive.get(0) <= cur) {
                    arrive.remove(0);
                }
                space--;
            }

            
            cur += t; // 다음 버스 도착 시각
            n--;
        }
        
        
        return answer;
    }
}
