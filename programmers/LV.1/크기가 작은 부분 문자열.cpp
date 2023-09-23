#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    string str = "";
    for(int i=0; i<t.length(); i++) {
        if(str.length()<p.length()) { // p의 길이에 못미치면
            str+=t[i]; // i번째 수 붙이기
        } else if (str.length()==p.length()) { // p의 길이가 되었다면
            if(stoll(str)<=stoll(p)) { // p보다 작거나 같다면
                answer++;
            }
            str+=t[i]; // i번째 수를 붙이고
            str.erase(str.begin()); // 첫번째 수를 제거하고
        }
    }
    
    if(stoll(str)<=stoll(p)) { // 위의 반복문에서 t의 마지막 문자열을 붙이고 검증 안하고 탈출하므로. 마지막 검증 필요
        answer++;
    }
    
    
    return answer;
}
