/*
BOJ 2211번: 네트워크 복구
DATE: 2022-01-10
Dijkstra Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9
using namespace std;

vector<pair<int,int>> graph[MAX];
int d[MAX];
int route[MAX]; // route[a] = b: a번에 최소로 도달하기 위해서는 b 정점에서 와야 한다.

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 

    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()){
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d[cur] < distance) continue;
        for(int i = 0 ; i < graph[cur].size() ; i++){
            int newDistance = graph[cur][i].second;
            int next = graph[cur][i].first;

            if(distance + newDistance < d[next]){
                route[next] = cur;
                d[next] = distance + newDistance;
                pq.push({d[next], next});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int a, b, c;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(d, d + n + 1, INF);
    dijkstra(1);

    cout << n - 1 << '\n';
    for(int i = 2 ; i <= n ; i++) cout << route[i] << " " << i << '\n';

    return 0;
}