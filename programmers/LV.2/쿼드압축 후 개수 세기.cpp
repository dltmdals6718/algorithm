#include <string>
#include <vector>
#include <iostream>
using namespace std;

void recursion(vector<vector<int>> &arr, int x, int y, int n, pair<int, int> &p) {
    
    // 위치 arr[y][x]에서 arr[y+n][x+n]까지 arr[y][x]의 값과 동일한지 체크.
    for(int i=y; i<y+n; i++) {
        for(int j=x; j<x+n; j++) {
            if(arr[y][x] != arr[i][j]) { // 시작점 값과 다르다면 4분할
                // 모두 n의 길이는 절반이 된다. 다음 좌표는 모두 각각 n/2를 더한 위치가 된다.
                recursion(arr, x, y, n/2, p);
                recursion(arr, x+n/2, y, n/2, p);
                recursion(arr, x, y+n/2, n/2, p);
                recursion(arr, x+n/2, y+n/2, n/2, p);
                return; // 일치하지 않는다면 위의 쪼갠 순환호출만 수행하고 반복문을 더 돌리지 않는다.
            }
        }
    }
    
    // 이까지 온것은 시작지점 [y][x] 부터 길이 n만큼 모두 값이 동일하다는 것임.
    if(arr[y][x]==0) // 시작 지점의 값이 0이면 p의 첫번째 값을 +1
        p.first++;
    else
        p.second++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    pair<int,int> p;
    recursion(arr, 0, 0, arr.size(), p); // 첫 검사 길이는 배열의 길이이다.
    answer.push_back(p.first);
    answer.push_back(p.second);
    return answer;
}
