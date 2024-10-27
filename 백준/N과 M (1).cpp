#include <iostream>
#include <string>
using namespace std;

void sol(int idx, int arr[], bool visit[], int N, int M) {
    
    if (idx == M) {
        
        for (int i=0; i<M; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        
        return;
    }
    
    
    for (int i=1; i<=N; i++) {
        
        if (visit[i] == false) {
            visit[i] = true;
            arr[idx] = i;
            sol(idx+1, arr, visit, N, M);
            visit[i] = false;
        }
        
    }
    
    
    
}

int main() {
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin>>N>>M;
    
    int arr[M];
    fill(&arr[0], &arr[M], 0);
    
    bool visit[N+1];
    fill(&visit[0], &visit[N+1], false);
    sol(0, arr, visit, N, M);
    
    
}
