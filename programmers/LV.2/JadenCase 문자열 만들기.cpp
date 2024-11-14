#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string word = "";
    for (int i=0; i<s.length(); i++) {
        if (s[i] == ' ' || i == s.length() - 1) {
            if (word[0] >= 'a' && word[0] <= 'z')
                word[0] -= 'a' - 'A';
            
            if (i == s.length() - 1)
                word += s[i];
            
            answer += word;
            
            if(i != s.length() - 1)
                answer += " ";
            word = "";
        } else {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] -= 'A' - 'a';
            word += s[i];
        }
    }
    
    return answer;
}
