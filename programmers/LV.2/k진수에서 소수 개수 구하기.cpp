#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

string convert(int n, int k) {
    
    string str = "";
    
    if (k == 0)
        return "0";
    
    
    while (k > 0) {
        
        if (n > 10) {
            str += (char) ((k % n) + 'A' - 10);
        } else {    
            str += to_string(k % n);
        }
    
        k /= n;
        
    }
    
    reverse(str.begin(), str.end());
    return str;
    
}


bool isPrime(string str) {
    
    long long int number = stoll(str);
    
    if (number == 1)
        return false;
    
    for (long long int i=2; i<=sqrt(number); i++) {
        if (number % i == 0)
            return false;
    }
    
    
    
    return true;
}

bool conditionTest(string str, int left, int right) {
    
    if (left - 1 >= 0 && str[left-1] == '0' && right + 1 < str.length() && str[right+1] == '0')
        return true;
    
    if (left == 0 && right + 1 < str.length() && str[right+1] == '0')
        return true;
    
    if (left - 1 >= 0 && str[left-1] == '0' && right == str.length() - 1)
        return true;
    
    if (left == 0 && right == str.length() - 1)
        return true;

    return false;
}


int solution(int n, int k) {
    int answer = 0;
    
    string number = convert(k, n);
    string str = "";
    int left = 0;
    int right = 0;
    for (int i=0; i<number.length(); i++) {
        if (number[i] == '0') {
            if (str.length() != 0) {
                if (isPrime(str) && conditionTest(number, left, right)) {
                    cout<<str<<endl;
                    answer++;
                }
            }
            
            left = i;
            right = i;
            str = "";
        } else {
            str += number[i];
            
            if (str.length() == 1) {
                left = i;
                right = i;
            } else {
                right++;
            }
        
        }
        
        if (i == number.length()-1 && str.length() != 0) {
            if(isPrime(str) && conditionTest(number, left, right)) {
                cout<<str<<endl;
                answer++;
            }
                
        }
        
    }
    
    
    return answer;
}
