/*
BOJ 10282번: 해킹
DATE: 2022-01-11
Dijkstra Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
#define INF 1e9
using namespace std;

vector<pair<int,int>> graph[MAX];
int dst[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 거리, 노드

    pq.push({0, start});
    dst[start] = 0;

    while(!pq.empty()){
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(distance > dst[cur]) continue;
        for(int i = 0 ; i < graph[cur].size() ; i++){
            int newDistance = graph[cur][i].second;
            int next = graph[cur][i].first;

            if(distance + newDistance < dst[next]){
                dst[next] = distance + newDistance;
                pq.push({dst[next], next});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    int n, d, c;
    int a, b, s;
    cin >> t;

    for(int i = 0 ; i < t ; i++){
        cin >> n >> d >> c;

        for(int j = 0 ; j < d ; j++){
            cin >> a >> b >> s;
            graph[b].push_back({a, s}); // a가 b를 의존 
        }

        fill(dst, dst + n + 1, INF);
        dijkstra(c);
        
        int maximum = -1, cnt = 0;

        for(int j = 1 ; j <= n ; j++) {
            if(dst[j] == INF) continue;
            maximum = max(maximum, dst[j]);
            cnt++;
        }

        cout << cnt << " " << maximum << '\n';

        for(int j = 1 ; j <= n ; j++) graph[j].clear();
    }

    return 0;
}