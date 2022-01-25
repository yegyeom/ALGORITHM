/*
BOJ 18352번: 특정 거리의 도시 찾기
DATE: 2021-02-25
Dijkstra Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 300001
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[MAX];
int d[MAX];

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for(int i = 0 ; i < graph[now].size() ; i++){
            int next = graph[now][i].first;
            int nCost = cost + graph[now][i].second;
            if(nCost < d[next]){
                d[next] = nCost;
                pq.push(make_pair(d[next], next));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, m, k, x, check;
    cin >> n >> m >> k >> x;

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(make_pair(b, 1)); 
    }

    for(int i = 1 ; i <= n ; i++){
        d[i] = INF;
    }

    dijkstra(x);

    for(int i = 1 ; i <= n ; i++){
        if(d[i] == k) {
            pq.push(i);
        }
    }

    if(pq.empty())
        cout << -1;
    else{
        while(!pq.empty()){
            cout << pq.top() << "\n";
            pq.pop();
        }
    }

    return 0;
}