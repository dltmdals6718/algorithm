import java.util.*;
class Solution {
    
    class Song {
        int idx; // 고유 번호
        int play; // 재생 횟수
        
        public Song(int idx, int play) {
            this.idx = idx;
            this.play = play;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        
        Map<String, Integer> genresCnt = new HashMap<String, Integer>(); // 장르별 총 재생 횟수
        Map<String, List<Song>> genresSong = new HashMap<String, List<Song>>(); // 장르별 노래
        
        for(int i=0; i<genres.length; i++) {
            
            // 장르별 재생 횟수 갱신
            if(genresCnt.get(genres[i]) == null)
                genresCnt.put(genres[i], plays[i]);
            else
                genresCnt.put(genres[i], genresCnt.get(genres[i]) + plays[i]);
            
            // 장르별 노래 추가
            if(genresSong.get(genres[i]) == null)
                genresSong.put(genres[i], new ArrayList<>());
            genresSong.get(genres[i]).add(new Song(i, plays[i]));
            
        }
        
        // 많이 재생된 노래 장르별 정렬
        List<String> genre = new ArrayList<>(genresCnt.keySet());
        genre.sort((o1, o2) -> {
            return genresCnt.get(o2) - genresCnt.get(o1);
        });
        
        List<Integer> result = new ArrayList<>();
        
        // 재생 횟수가 많은 장르부터 탐색
        for(int i=0; i<genre.size(); i++) {
            
            // 장르에 속한 노래
            List<Song> songs = genresSong.get(genre.get(i)); // genre[i]가 아니라 genre.get(i) 였음...
            songs.sort((o1, o2) -> {
                if(o1.play == o2.play) { // 재생 횟수가 같다면
                    return o1.idx - o2.idx;
                } else {
                    return o2.play - o1.play;
                }
            });
            
            
            result.add(songs.get(0).idx);
            // if(songs.get(1) != null) 1번째 인덱스가 null이면 get(1)에서 바로 NullException이 뜨니 주의!
            if(songs.size()>1) 
                result.add(songs.get(1).idx);
        }
        
        int[] answer = new int[result.size()];
        for(int i=0; i<result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
    // Arrays.sort(genre, (o1, o2) -> {
// return genresCnt.get(o1) - genresCnt.get(o2);
// }); Arrays.sort 이건 배열 int[] 정렬시 사용

// Map: keySet(), values()

        
// String[] s - i<s.length
// j<s[i].length()
// List와 같은 컬렉션은 size()
// for(int i=0; i<genre.size(); i++) {
// System.out.println(genre.get(i)); // genre[i]가 아니고 genre.get(i) 임...
// }
}
