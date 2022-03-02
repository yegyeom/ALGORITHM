/*
BOJ 1197번: 최소 스패닝 트리
DATE: 2022-03-02
Prim Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define MAX 10001
using namespace std;

vector<pii> edge[MAX];
bool visited[MAX];
int ans;

void prim(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int dis = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(visited[cur]) continue; 
        visited[cur] = true;
        ans += dis;

        for(int i = 0 ; i < edge[cur].size() ; i++){
            if(visited[edge[cur][i].second]) continue;
            pq.push(edge[cur][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v, e;
    int a, b, c;
    cin >> v >> e;

    for(int i = 0 ; i < e ; i++){
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
        edge[b].push_back({c, a});
    }

    prim();
    cout << ans;

    return 0;
}