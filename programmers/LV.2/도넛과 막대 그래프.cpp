#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void searchNode(int start, vector<vector<int>>& input, vector<vector<int>>& output, vector<int>& graphCnt) {
    
    queue<int> q;
    bool visit[1000001];
    fill(visit, &visit[1000001], false);
    
    q.push(start);
    visit[start] = true;
    while(!q.empty()) {
        
        int cur = q.front();
        q.pop();
        
        if (output[cur].size()==0) {
            graphCnt[1]++;
            return;
        } else if (output[cur].size()==2) {
            graphCnt[2]++;
            return;
        }
        
        for(int i=0; i<output[cur].size(); i++) {
            if (visit[output[cur][i]]==false) {
                q.push(output[cur][i]);
                visit[output[cur][i]] = true;
            } else if (visit[output[cur][i]] && output[cur][i]==start) { // 다음 방문지가 이미 방문한곳인데 그게 시작점이라면
                graphCnt[0]++;
                return;
            }
        }
        
    }
    
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    vector<vector<int>> input(1000001);
    vector<vector<int>> output(1000001);
    
    for(int i=0; i<edges.size(); i++) {
        int start = edges[i][0];
        int end = edges[i][1];
        
        input[end].push_back(start);
        output[start].push_back(end);
    }
    
    for(int i=1; i<=edges.size(); i++) {
        if (input[i].size()==0 && output[i].size()>=2) { // 생성한 정점
            answer.push_back(i);
        }
    }
    
    int createNode = answer[0];
    vector<int> graphCnt(3); // 도넛, 막대, 8자
    for(int i=0; i<output[createNode].size(); i++) { // 생성된 정점은 각각의 그래프의 임의 정점을 가리킨다.
        searchNode(output[createNode][i], input, output, graphCnt);
    }
    
    // answer.push_back(output[createNode].size()-graphCnt[1]-graphCnt[2]); <- 도넛 개수 = 총 그래프 개수 - 막대 그래프 개수 - 8자 그래프
    answer.push_back(graphCnt[0]);
    answer.push_back(graphCnt[1]);
    answer.push_back(graphCnt[2]);
    return answer;
}
