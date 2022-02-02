/*
BOJ 7576번: 토마토
DATE: 2022-02-02
BFS
*/
#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

queue<pair<int,int>> q;
int m, n;
int arr[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny]) continue;

            q.push({nx, ny});
            arr[nx][ny] = arr[x][y] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    cin >> m >> n;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) q.push({i, j});
        }
    }

    bfs();

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(arr[i][j] == 0) { // 익지 않은 토마토 존재
                cout << -1;
                return 0;
            }
            else if(arr[i][j] > ans) ans = arr[i][j]; 
        }
    }

    cout << ans - 1;

    return 0;
}