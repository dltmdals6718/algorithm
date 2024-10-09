#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, bool> m;
    for (int i=0; i<skill.length(); i++) {
        m.insert({skill[i], true});
    }
    
    for (int i=0; i<skill_trees.size(); i++) {
        
        string str = "";
        
        for (int j=0; j<skill_trees[i].length(); j++) {
            if (m.find(skill_trees[i][j]) != m.end())
                str += skill_trees[i][j];
        }
        
        bool able = true;
        for (int j=0; j<str.length(); j++){
            if (str[j] != skill[j])
                able = false;
        }
        
        if (able)
            answer++;
            
        
    }
    
    
    
    return answer;
}
