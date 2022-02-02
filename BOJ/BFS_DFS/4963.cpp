/*
BOJ 4963번: 섬의 개수
DATE: 2022-02-02
BFS
*/
#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

int w, h;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int x, int y) {
    queue<pair<int,int>> q;

    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 8 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny] || !arr[nx][ny]) continue;

            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(1) {
        cin >> w >> h;

        if(w == 0 && h == 0) break;
        int ans = 0;

        for(int i = 0 ; i < h ; i++) {
            for(int j = 0 ; j < w ; j++) {
                cin >> arr[i][j];
            }
        }

        for(int i = 0 ; i < h ; i++) {
            for(int j = 0 ; j < w ; j++) {
                if(arr[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    ans++;
                }
            }
        }

        cout << ans << '\n';

        fill(&arr[0][0], &arr[h - 1][w], 0);
        fill(&visited[0][0], &visited[h - 1][w], false);
    }

    return 0;
}