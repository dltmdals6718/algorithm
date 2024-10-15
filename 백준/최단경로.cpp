#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

void sol(int K, vector<pair<int, int>> (&v)[20001], int V) {
    
    int dis[20001]; // 최소 비용
    fill(&dis[0], &dis[20001], 987654321);
    
    dis[K] = 0;
    
    priority_queue<pair<int, int>> pq; // (비용, 노드)
    pq.push(make_pair(0, K));
    
    while (!pq.empty()) {
        
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for (int i=0; i<v[cur].size(); i++) {
            
            int next = v[cur][i].first;
            int ncost = cost + v[cur][i].second;
            
            if (dis[next] > ncost) {
                dis[next] = ncost;
                pq.push(make_pair(-dis[next], next));
            }
        }
        
    }
    
    for (int i=1; i<=V; i++) {
        if (dis[i] == 987654321) {
            cout<<"INF\n";
        } else {
            cout<<dis[i]<<"\n";
        }
    }
    
    
    
    return;
}

int main() {
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int V, E;
    cin>>V>>E;
    
    int K;
    cin>>K;
    
    vector<pair<int, int>> v[20001];
    for (int i=0; i<E; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        
        v[a].push_back(make_pair(b,c));
    }
    
    sol(K, v, V);
    
}
