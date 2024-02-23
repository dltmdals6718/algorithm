#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

// vector<int> &v를 안쓰고 vector<int> v 쓰면 배열 복사로인해 시간초과
int binary_search(int start, int end, int target, vector<int> &v) {
    
    int mid=0;
    while(start<=end) {
        mid = (start+end)/2;
        
        if(v[mid]<target)
            start = mid+1;
        else // 같다면 더 앞쪽의 값을 찾으러 가야함.
            end = mid-1;
    }
    
    // 위의 탐색을 거치면 target보다 작거나 같은수가 v[mid] 에 존재하게 된다.
    // 그렇다는건 v[mid]의 값이 target 보다 작다면 mid 위치 다음부터가 target 이상의 값임
    // v[mid] 의 값이 target과 같다면 mid 위치부터 끝까지가 target 이상의 값임. 
    
    if(v[mid]<target) // 작다면 
        return v.size()-(mid+1);
    else // 같다면 mid부터 끝까지 원소들이 만족하는 결과들임.
        return v.size()-mid;
        
    
}

void comb(string str, int idx, vector<string> &v, map<string,vector<int>> &m) {
    
    if(idx==4) {
        
        if(m.find(str) == m.end()) { // 존재하지 않는 조합
            vector<int> scoreList;
            scoreList.push_back(stoi(v[4]));
            m.insert({str, scoreList});
        } else {
            m[str].push_back(stoi(v[4])); // 점수 추가
        }
        
        return;
    }
    
    comb(str+"-", idx+1, v, m);
    comb(str+v[idx], idx+1, v, m);
    
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    map<string,vector<int>> m; // (조합, 점수들)
    
    for(int i=0; i<info.size(); i++) {
        
        vector<string> v;
        
        // v에 개발언어, 직군, 경력, 소울 푸드 추가
        int pos=0;
        for(int j=0; j<info[i].size(); j++) {
            if(info[i][j]==' ') {
                
                // v.push_back(info[i].substr(pos, j-pos)); <- substr O(N)이라 아래의 코드로 바꿈.
                string str = "";
                for(int idx=pos; idx<j; idx++)
                    str += info[i][idx];
                v.push_back(str);
                pos=j+1;
            }  
        }
        
        // 끝에 남은 점수 v에 추가
        string str = "";
        for(int idx=pos; idx<info[i].size(); idx++)
            str += info[i][idx];
        v.push_back(str);
        
        comb("", 0, v, m); // 해당 지원서로 모든 조합하여 m에 점수 추가
        
    }
    
    // map 전체 정렬 해주기 - 쿼리 내부에 정렬코드를 넣으면 같은 쿼리에 대해 또 정렬하는 경우가 발생하기에 방지
    map<string, vector<int>>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }
    
    
    for(int i=0; i<query.size(); i++) {
        vector<string> v;
        
        // i번째 쿼리의 조건 추출 과정
        int pos=0;
        string key = ""; // 쿼리에서 조건만 붙여나감
        for(int j=0; j<query[i].size(); j++) {
            if(query[i][j]==' ') {
                
                string word = ""; // 조건
                for(int idx=pos; idx<j; idx++)
                    word += query[i][idx];
                v.push_back(word);
                
                if(word!="and") // and가 아니라면 key에 추가
                    key+=word;
                pos=j+1;
            }  
        }
        
        // i번째 쿼리의 점수 추출 과정
        string score = "";
        for(int idx=pos; idx<query[i].size(); idx++)
            score += query[i][idx];
        v.push_back(score);
        
        if (m.find(key)==m.end()) { // 조합이 존재하지 않으면 0명
            answer.push_back(0);
        } else { // 존재하면 이진탐색을 통해 인원수 추가
            vector<int> scoreList = m[key];

            int cnt = binary_search(0, scoreList.size()-1, stoi(score), scoreList);
            answer.push_back(cnt);
        }
    }
    
    
    return answer;
}
