#include <iostream>
using namespace std;
int main() {
    
    int N;
    cin>>N;
    
    int arr[100][100];
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>arr[i][j];
        }
    }
    
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                
                if (arr[i][k] == 1 && arr[k][j] == 1) {
                    arr[i][j] = 1;
                }
                
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
}
