/*
BOJ 5014번: 스타트링크
DATE: 2022-04-28
BFS
*/
#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool visited[1000001];

void bfs(int S){
    queue<pair<int,int>> q;
    q.push({S, 0});
    visited[S] = true;
    
    while(!q.empty()){
        int floor = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(floor == G) {
            cout << cnt;
            return;
        }

        int upstairs = floor + U;
        int downstairs = floor - D;

        if(upstairs > 0 && upstairs <= F && !visited[upstairs]) {
            q.push({upstairs, cnt + 1});
            visited[upstairs] = true;
        }
        if(downstairs > 0 && downstairs <= F && !visited[downstairs]) {
            q.push({downstairs, cnt + 1});
            visited[downstairs] = true;
        }
    }

    cout << "use the stairs";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> F >> S >> G >> U >> D; // 총 F층, 현재 층, 도착 층, Up, Down

    bfs(S);

    return 0;
}