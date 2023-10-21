#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    answer+="0";
    for(int i=food.size()-1; i>=1; i--) {
        for(int j=0; j<food[i]/2; j++) { // 앞뒤로 2개의 음식을 붙일 수 있는만큼 붙임
            answer.insert(0, to_string(i));
            answer.insert(answer.length(), to_string(i));
        }
    }
    return answer;
}
