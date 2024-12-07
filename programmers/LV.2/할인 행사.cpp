#include <string>
#include <vector>
#include <map>
using namespace std;


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> buy;
    for (int i=0; i<buy.size(); i++) {
        buy.insert({want[i], number[i]});
    }
    
    map<string, int> sale;
    for (int i=0; i<10; i++) {
        if (sale.find(discount[i]) == sale.end())
            sale.insert({discount[i], 1});
        else
            sale[discount[i]]++;
    }
    
    
    bool flag = true;
    for (int i=0; i<want.size(); i++) {
        if (sale.find(want[i]) == sale.end()) {
            flag = false;
            break;
        } else {
            
            if (sale.find(want[i])->second < number[i])
                flag = false;
        }
    }
    
    if (flag)
        answer++;
    
    for (int i=10; i<discount.size(); i++) {
        
        sale[discount[i-10]]--; // 첫날
        
        if (sale.find(discount[i]) == sale.end()) {
            sale.insert({discount[i], 1});
        } else {
            sale[discount[i]]++;
        }
        
        bool flag = true;
        for (int j=0; j<want.size(); j++) {
            if (sale.find(want[j]) == sale.end()) {
                flag = false;
                break;
            } else {
                if (sale.find(want[j])->second < number[j])
                    flag = false;
            }
        }
        if (flag)
            answer++;
        
        
        
    }
    
    
    return answer;
}
