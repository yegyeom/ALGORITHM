/*
BOJ 5972번: 택배 배송
2021-12-29
Dijkstra Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 50001
#define INF 1e9
using namespace std;

int d[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()) {
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(distance > d[cur]) continue; 
        for(int i = 0 ; i < graph[cur].size() ; i++) {
            int newDistance = graph[cur][i].second;
            int next = graph[cur][i].first;

            if(newDistance + distance < d[next]) {
                d[next] = newDistance + distance;
                pq.push({d[next], next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int a, b, c;

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(d, d + n + 1, INF);

    dijkstra(1);
    cout << d[n];
    
    return 0;
}