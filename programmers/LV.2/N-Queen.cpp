#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool able(int row, int n, int arr[]) {
    
    for (int i=0; i<row; i++) {
        if (arr[i] == arr[row]) // 같은 열에 존재한다면 불가능
            return false;
        
        // 대각선에 존재한다면 불가능
        if (abs(i - row) == abs(arr[i] - arr[row]))
            return false;
        
    }
    
    return true;
}

void sol(int row, int n, int arr[], int &answer) {
    
    if (row == n) {
        answer++;
        return;
    }
    
    for (int i=0; i<n; i++) {
        arr[row] = i;
        if (able(row, n, arr)) {
            sol(row+1, n, arr, answer);
        }
        
    }
    
    return;
}

int solution(int n) {
    int answer = 0;
    
    int arr[n];
    fill(&arr[0], &arr[n], 0);
    
    sol(0, n, arr, answer);
        
    
    return answer;
}
