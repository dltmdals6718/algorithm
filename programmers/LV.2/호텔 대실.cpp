#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> book_time) {

    int answer = 0;
    int arr[1450];
    fill(&arr[0], &arr[1450], 0);
    // 24:00는 1440분이고 9분을 더하면 1449분이다. 배열 크기 1450으로 설정
    
    for(int i=0; i<book_time.size(); i++) {
        string startTime, endTime;
        int startMin=0;
        int endMin=0;
        startMin+=(book_time[i][0][0]-'0')*600;
        startMin+=(book_time[i][0][1]-'0')*60;
        startMin+=(book_time[i][0][3]-'0')*10;
        startMin+=(book_time[i][0][4]-'0');
        
        endMin+=(book_time[i][1][0]-'0')*600;
        endMin+=(book_time[i][1][1]-'0')*60;
        endMin+=(book_time[i][1][3]-'0')*10;
        endMin+=book_time[i][1][4]-'0';
        endMin+=9;

        cout<<startMin<<" "<<endMin<<endl;
        for(int idx=startMin; idx<=endMin; idx++) {
            arr[idx]++;
            answer=max(answer, arr[idx]);
        }
        
    }
    

    return answer;
}
