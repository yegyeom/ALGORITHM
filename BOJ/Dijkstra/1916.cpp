/*
BOJ 1916번: 최소비용 구하기
2021-12-28
Dijkstra Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 100000001
using namespace std;

int d[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra(int start) {    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 거리, 노드

    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()) {
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d[cur] < distance) continue;
        for(int i = 0 ; i < graph[cur].size() ; i++) {
            int newDistance = graph[cur][i].second;
            int next = graph[cur][i].first;

            if(distance + newDistance < d[next]) {
                d[next] = distance + newDistance;
                pq.push({d[next], next});
            }
        }
    }
}

int main() {
    int n, m;
    int x, y, z;
    int a, b;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++) {
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
    }

    cin >> a >> b;

    fill(d, d + n + 1, INF);
    dijkstra(a);

    cout << d[b];

    return 0;
}