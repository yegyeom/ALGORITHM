/*
programmers Level 2: 배달
date: 2022-06-03
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 51
#define INF 1e9
using namespace std;

int dst[MAX];
vector<pair<int,int>> graph[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, start});
    dst[start] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for(int i = 0 ; i < graph[node].size() ; i++){
            int nextNode = graph[node][i].first;
            int nextCost = graph[node][i].second;
            
            if(dst[nextNode] > cost + nextCost){
                dst[nextNode] = cost + nextCost;
                pq.push({dst[nextNode], nextNode});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    for(auto i : road){
        int a = i[0];
        int b = i[1];
        int c = i[2];
        
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    fill(dst, dst+MAX, INF);
    dijkstra(1);
    
    for(int i = 1 ; i <= N ; i++){
        if(dst[i] != INF && dst[i] <= K) answer++;
    }
    
    return answer;
}