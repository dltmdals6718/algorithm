#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    
    map<string, string> m;
    
    for (int i=0; i<record.size(); i++) {
        
        string status ="";
        string id = "";
        string nickname = "";
        
        int idx = 0;
        while (record[i][idx] != ' ') {
            status += record[i][idx];
            idx++;
        }
        idx++;
        
        while (record[i][idx] != ' ' && record[i][idx] != '\0') {
            id += record[i][idx];
            idx++;
        }
        idx++;
        
        
        while (record[i][idx] != '\0') {
            nickname += record[i][idx];
            idx++;
        }
        
        if (status == "Enter" || status == "Change") {
            
            
            if (m.find(id) == m.end())
                m.insert({id, nickname});
            else
                m[id] = nickname;
            
        }
        
    }

    
    for (int i=0; i<record.size(); i++) {
        string status ="";
        string id = "";
        string nickname = "";
        
        int idx = 0;
        while (record[i][idx] != ' ') {
            status += record[i][idx];
            idx++;
        }
        idx++;
        
        while (record[i][idx] != ' ' && record[i][idx] != '\0') {
            id += record[i][idx];
            idx++;
        }
        idx++;
        
        
        while (record[i][idx] != '\0') {
            nickname += record[i][idx];
            idx++;
        }
        
        if (status == "Enter")
            answer.push_back(m[id] + "님이 들어왔습니다.");
        else if (status == "Leave")
            answer.push_back(m[id] + "님이 나갔습니다.");
        
        
    }
    
    return answer;
}
