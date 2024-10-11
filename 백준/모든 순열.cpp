#include <iostream>
#include <string>
using namespace std;

void sol(int cnt, int N, bool visit[], string str) {
    
    if (cnt == N) {

        for (int i=0; i<str.length(); i++) {
            cout<<str[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for (int i=1; i<=N; i++) {
        if (visit[i] == false) {
            visit[i] = true;
            sol(cnt+1, N, visit, str + to_string(i));
            visit[i] = false;
        }
    }
    
    return;
}

int main(void) {
    
    int N;
    cin>>N;
    
    bool visit[N+1];
    fill(&visit[0], &visit[N+1], false);
    sol(0, N, visit, "");
}
