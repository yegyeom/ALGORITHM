/*
BOJ 13549번: 숨바꼭질 3
2022-01-12
Dijkstra Algorithm ver.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF 1e9
using namespace std;

vector<pair<int,int>> graph[MAX];
int sec[MAX];
int mv[3] = {-1, 1, 2};

void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 시간, 위치
    
    pq.push({0, start});
    sec[start] = 0;

    while(!pq.empty()){
        int curTime = pq.top().first;
        int curLocation = pq.top().second;
        int nextLocation, nextTime;
        pq.pop();

        if(curTime > sec[curLocation]) continue;
        for(int i = 0 ; i < 3 ; i++) {
            if(i < 2) {
                nextLocation = curLocation + mv[i];
                nextTime = sec[curLocation] + 1;
            }
            else {
                nextLocation = curLocation * 2;
                nextTime = sec[curLocation];
            }

            if(nextLocation < 0 || nextLocation > MAX - 1) continue;
            if(sec[nextLocation] > nextTime) {
                sec[nextLocation] = nextTime;
                pq.push({nextTime, nextLocation});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;

    fill(sec, sec + MAX, INF);
    dijkstra(n);
    cout << sec[k];

    return 0;
}