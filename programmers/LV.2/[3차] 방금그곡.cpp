#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void convert(string &sheet) {
    map<char, char> m;
    m.insert({'C', 'Q'});
    m.insert({'D', 'R'});
    m.insert({'F', 'S'});
    m.insert({'G', 'T'});
    m.insert({'A', 'U'});
    
    for(int i=0; i<sheet.length(); i++) {
        if(sheet[i]=='#') { // '#' 발견시 '#' 앞의 문자를 변환하고 '#' 문자 제거
            sheet[i-1]=m[sheet[i-1]];
            sheet.erase(sheet.begin()+i);
            i--;
        }
    }
    
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    int answerPlayTime=-1;
    for(int i=0; i<musicinfos.size(); i++) {
        string title;
        string sheet;
        int playTime=0;
        //처음 "XX:XX,XX:XX" 형식은 고정되어있기에 바로 시간 뽑아낼 수 있다.
    
        playTime+=(musicinfos[i][6]-'0')*600;
        playTime+=(musicinfos[i][7]-'0')*60;
        playTime+=(musicinfos[i][9]-'0')*10;
        playTime+=musicinfos[i][10]-'0';

        playTime-=(musicinfos[i][0]-'0')*600;
        playTime-=(musicinfos[i][1]-'0')*60;
        playTime-=(musicinfos[i][3]-'0')*10;
        playTime-=musicinfos[i][4]-'0';
        
        for(int j=12; j<musicinfos[i].size(); j++) { // 제목, 악보 분리
            if(musicinfos[i][j]==',') {
                title = musicinfos[i].substr(12, j-12);
                sheet = musicinfos[i].substr(j+1);
                break;
            }
        }

        // 문자 하나하나 비교하는 find 함수 실행시 ABC를 찾아야하는데 ABC#에서 일치한다고 판별해버리니
        // C#들을 다른 문자 하나로 치환하는 과정이 필요함.
        convert(sheet);
        
        string radio;
        int idx=0; // 재생 시간만큼 라디오에서 재생된다.
        for(int j=0; j<playTime; j++) {
            radio+=sheet[idx++];
            if(idx==sheet.length())
                idx=0;
        }
        
        
        convert(m);
        if(radio.find(m)!=string::npos) { //먼저 입력된 음악부터 정답을 찾으므로 순서에 대한 정보는 생각하지 않아도 된다.
            if(answerPlayTime<playTime) { //현재 답의 재생시간보다 크다면
                answerPlayTime=playTime; //재생시간 갱신
                answer=title; //답 갱신
            }
        }
        
    }
    return answer; // substr, find 메서드 공부
}
