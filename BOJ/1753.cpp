#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[MAX];
int d[MAX];

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //거리, 노드
   
    pq.push(make_pair(0, start));
    d[start] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < graph[now].size() ; i++){
            int next = graph[now][i].first;
            int nCost = graph[now][i].second;
            if(cost + nCost < d[next]){
                d[next] = cost + nCost;
                pq.push(make_pair(d[next], next));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v, e, start;

    cin >> v >> e >> start;

    for(int i = 0 ; i < e ; i++){
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
    }

    for(int i = 1 ; i <= v ; i++){
        d[i] = INF;
    }

    dijkstra(start);

    for(int i = 1 ; i <= v ; i++){
        if(d[i] == INF)
            cout << "INF" << "\n";
        else 
            cout << d[i] << "\n";
    }

    return 0;
}