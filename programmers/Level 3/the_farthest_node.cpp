/*
programmers Level 3: 가장 먼 노드
2022-02-22
BFS
*/
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> graph[n + 1];
    vector<bool> visited(n + 1, false);
    vector<int> d(n + 1, 0);
    queue<int> q;
    int answer = 0;
    
    for(int i = 0 ; i < edge.size() ; i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(1);
    d[1] = 0;
    visited[1] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i = 0 ; i < graph[cur].size() ; i++){
            if(!visited[graph[cur][i]]) {
                int nextNode = graph[cur][i];
                int nextDistance = d[cur] + 1;
                
                d[nextNode] = nextDistance;
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
    
    sort(d.begin(), d.end(), greater<>());
    
    for(int i = 0 ; i <= n ; i++){
        if(d[i] != d[0]) break;
        answer++;
    }
    
    return answer;
}