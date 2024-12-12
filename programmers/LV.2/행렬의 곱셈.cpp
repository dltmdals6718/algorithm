#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    // 2x3 3x2
    // 1 1 1    1 1
    // 1 1 1    1 1
    //          1 1
    
    cout<<arr1.size()<<" "<<arr2[0].size();
    for (int i=0; i<arr1.size(); i++) { // 결과 행렬 i행
        vector<int> v;
        for (int j=0; j<arr2[0].size(); j++) { // 결과 행렬 j열
            // 결과 행렬 i행 j열의 값은 arr1의 i행과 arr2의 j열의 곱의 합이다.
            
            int sum = 0;
            for (int k=0; k<arr1[i].size(); k++)
                sum += arr1[i][k] * arr2[k][j];
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    
    return answer;
}
