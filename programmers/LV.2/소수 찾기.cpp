#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;


bool isPrime(int n) {
    
    if (n == 1 || n == 0)
        return false;
    
    for (int i=2; i <= sqrt(n); i++) {
        
        if (n % i == 0)
            return false;
        
    }
    
    return true;
}


void dfs(string numbers, bool (&visit)[7], string str, map<int, bool> &m, int &answer) {
    
    
    if (isPrime(stoi(str))) {
        if (m.find(stoi(str)) == m.end()) {
            m.insert({stoi(str), true});
            answer++;
        }
    }
    
    for (int i=0; i<numbers.length(); i++) {
        if (visit[i] == false) {
            visit[i] = true;
            dfs(numbers, visit, str+numbers[i], m, answer);
            visit[i] = false;
        }
    }
    
}


int solution(string numbers) {
    int answer = 0;
    
    bool visit[7];
    map<int, bool> m;
    for (int i=0; i<numbers.length(); i++) {
        visit[i] = true;
        string str = "";
        str += numbers[i];
        dfs(numbers, visit, str, m, answer);
        visit[i] = false;
    }
    
    
    
    
    return answer;
}
