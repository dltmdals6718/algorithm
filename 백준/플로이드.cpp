#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    
    int n, m;
    cin>>n>>m;
    
    int arr[101][101];
    fill(&arr[0][0], &arr[100][101], 987654321);
    
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        arr[a][b] = min(arr[a][b], c);
    }
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i != j)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if(arr[i][j] == 987654321) {
                cout<<"0 ";
            } else {
                cout<<arr[i][j]<<" ";
            }
            
        }
        cout<<"\n";
    }
    
    
    
}
