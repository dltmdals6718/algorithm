#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    // 현재 방문해야할 집 (젤 끝 집부터 방문)
    int dIdx = n-1;
    int pIdx = n-1;
    
    
    // 배송과 픽업 인덱스가 둘다 -1이 될때까지 방문 
    while (dIdx >= 0 || pIdx >= 0) {
        
        // 배송이 필요한 가장 먼 집 인덱스
        while (dIdx>=0 && deliveries[dIdx] == 0) {
            dIdx--;
        }
        
        // 픽업이 필요한 가장 먼 집 인덱스
        while (pIdx>=0 && pickups[pIdx] == 0) {
            pIdx--;
        }
        
        // 배송과 픽업중 가장 먼 거리를 통해 배달과 픽업 모두 해결이 가능함.
        // 배달이 더 먼 거리라면 배달하고 창고로 가는길에 픽업하면 됨
        // 픽업이 더 먼 거리라면 픽업하러 가는길에 배달하면 됨
        // 즉 각각 수행한다고 생각하는게 편함.
    
        // 할일이 있는 최대 먼 거리를 통해 왕복 거리를 계산
        int distance = max(dIdx, pIdx) + 1;
        answer += distance*2;
        
        // 배송 가능한 용량
        int deliverCap = cap;
        while(deliverCap>0 && dIdx>=0) { // 배송 용량이 남아 있고, 배송 집이 남아 있다면
            if(deliveries[dIdx] <= deliverCap) { // 배송할 상자 <= 배송 가능 용량
                deliverCap -= deliveries[dIdx]; // 배송할 상자만큼 용량 줄임
                deliveries[dIdx] = 0; // 배송 요구만큼 모두 배송
            } else { // 배송할 상자 > 배송 가능 용량
                deliveries[dIdx] -= deliverCap; // 배송 용량만큼만 배송
                deliverCap = 0; // 베송 용량 0
                break;
            }
            dIdx--; // 다음 집 방문
        }
        
        int pickupCap = cap;
        while(pickupCap>0 && pIdx>=0) {
            if(pickups[pIdx] <= pickupCap) {
                pickupCap -= pickups[pIdx];
                pickups[pIdx] = 0;
            } else {
                pickups[pIdx] -= pickupCap;
                pickupCap = 0;
                break;
            }
            pIdx--;
        }
        
        
    }
    
    return answer;
}
