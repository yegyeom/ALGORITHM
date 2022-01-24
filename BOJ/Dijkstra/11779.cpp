/*
BOJ 11779번: 최소비용 구하기 2
2021-12-29
Dijkstra Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 100000001
using namespace std;

int d[MAX];
int route[MAX]; // route[a] = b: a번에 최소로 도달하기 위해서는 b 정점에서 와야 한다.
vector<pair<int, int>> graph[MAX];

void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 거리, 노드
    
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
                route[next] = cur;
                d[next] = distance + newDistance;
                pq.push({d[next], next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> answer;
    int n, m;
    int x, y, z;
    int start, end;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++) {
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
    }

    cin >> start >> end;

    fill(d, d + n + 1, INF);
    dijkstra(start);

    route[start] = 0;
    int idx = end;
    
    while(1) {
        if(route[idx] == 0) {
            answer.push_back(start);
            break;
        }
        answer.push_back(idx);
        idx = route[idx];
    }
    
    reverse(answer.begin(), answer.end());

    cout << d[end] << '\n';
    cout << answer.size() << '\n';
    for(int i = 0 ; i < answer.size() ; i++) cout << answer[i] << " ";

    return 0;
}