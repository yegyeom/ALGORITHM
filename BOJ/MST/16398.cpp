/*
BOJ 16398번: 행성 연결
DATE: 2022-03-02
Prim Algorithm
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define pii pair<int,int>
using namespace std;

vector<pii> edge[MAX];
bool visited[MAX];

long long prim(){
    long long ans = 0;
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
            if(!visited[edge[cur][i].second]) pq.push(edge[cur][i]);
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> num;

            if(i == j) continue;
            edge[i].push_back({num, j});
        }
    }

    cout << prim();

    return 0;
}