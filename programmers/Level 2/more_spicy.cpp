/*
programmers Level 2: 더 맵게
date: 2022-02-23
-
새로운 초기화 방법을 알게 되었다..! (line 12)
*/
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0;
    
    while(pq.top() < K){
        if(pq.size() == 1){
            answer = -1;
            break;
        }
        
        int a = pq.top(); 
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        pq.push(a + b * 2);
        answer++;
    }
    
    return answer;
}