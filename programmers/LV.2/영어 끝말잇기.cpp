#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, bool> m;
    
    m.insert({words[0], true});
    for (int i=1; i<words.size(); i++) {
        
        if (words[i].length() > 1 && words[i-1][words[i-1].length()-1] == words[i][0]) {
            if (m.find(words[i]) == m.end())
                m.insert({words[i], true});
            else { // 이미 부른 단어를 부름
                answer.push_back((i % n)+1);
                answer.push_back((i/n)+1);
                break;
            }
                
        } else { // 끝말을 잇지 못함 또는 길이가 1임
            answer.push_back((i % n)+1);
            answer.push_back((i/n)+1);
            break;
        }
        
        
    }
    
    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
