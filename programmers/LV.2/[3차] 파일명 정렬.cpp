#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(string a, string b) {
    
    // 소문자로 변환
    for (int i=0; i<a.length(); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] = 'a' + (a[i]- 'A');
    }
    
    for (int i=0; i<b.length(); i++) {
        if (b[i] >= 'A' && b[i] <= 'Z')
            b[i] = 'a' + (b[i] - 'A');
    }
    
    string ahead = "";
    string bhead = "";
    
    int aidx = 0;
    for (; aidx<a.length(); aidx++) {
        
        if (a[aidx] < '0' || a[aidx] > '9') {
            ahead += a[aidx];
        } else {
            break;
        }
        
    }
    
    int bidx=0;
    for (bidx=0; bidx<b.length(); bidx++) {
        
        if (b[bidx] < '0' || b[bidx] > '9') {
            bhead += b[bidx];
        } else {
            break;
        }
        
    }
    
    // number
    string anumber = "";
    string bnumber = "";
    
    for (; aidx<a.length(); aidx++) {
        if (a[aidx] >= '0' && a[aidx] <= '9' && anumber.length() < 5) {
            anumber += a[aidx];
        } else {
            break;
        }
        
    }
    for (; bidx<b.length(); bidx++) {
        if (b[bidx] >= '0' && b[bidx] <= '9' && bnumber.length() < 5) {
            bnumber += b[bidx];
        } else {
            break;
        }
    }

    if (ahead == bhead) {
        return stoi(anumber) < stoi(bnumber);
    } else {
        return ahead < bhead;
    }
    
    
    
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(), files.end(), comp);
    for (int i=0; i<files.size(); i++) {
        answer.push_back(files[i]);
    }
    return answer;
}
