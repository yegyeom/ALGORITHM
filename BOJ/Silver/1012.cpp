//BOJ 1012번: 유기농 배추
//2021-10-25
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[50][50];
bool visited[50][50];
int m, n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int,int>> q;

    q.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
         
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
            if(arr[nx][ny] == 0) continue;
            
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, k, x, y;
    cin >> t;

    for(int i = 0 ; i < t ; i++) {
        int cnt = 0;
        cin >> m >> n >> k;
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));

        for(int j = 0 ; j < k ; j++) {
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for(int j = 0 ; j < n ; j++) {
            for(int k = 0 ; k < m ; k++) {
                if(arr[j][k] == 1 && !visited[j][k]) {
                    cnt++;
                    bfs(j, k);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}