#include <string>
#include <vector>
#include <iostream>
using namespace std;

int fibo(int n, int (&arr)[100001]) {
    
    if (arr[n] != -1)
        return arr[n];
    
    arr[n] = (fibo(n-1, arr)% 1234567 + fibo(n-2, arr) % 1234567) % 1234567;
    return arr[n];
}

int solution(int n) {
    int answer = 0;
    int arr[100001];
    fill(arr, arr + 100001, -1);
    arr[0] = 0;
    arr[1] = 1;
    
    
    answer = fibo(n, arr);
    
    return answer;
}
