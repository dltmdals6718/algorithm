#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    long long minNumber = 0;
    long long maxNumber = 0;
    
    string number = "";
    bool first = true;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == ' ' || i == s.length() - 1) { // 공백이거나 마지막 문자라면
            number += s[i];
            
            long long convertedNumber = stoll(number);
            if (first) { // 첫번째 값이라면
                minNumber = convertedNumber;
                maxNumber = convertedNumber;
                first = false;
            }
            
            minNumber = min(minNumber, stoll(number));
            maxNumber = max(maxNumber, stoll(number));
            number = "";
        } else {
            number += s[i];
        }
    }
    
    answer += to_string(minNumber);
    answer += " " + to_string(maxNumber);

    return answer;
}
