//BOJ 14500번: 테트로미노
//2021-10-13
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = -1;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[500][500] = {0, }, visited[500][500] = {0, };

void solve_shape(int x, int y) { // ㅜ 모양은 dfs가 불가능
    if(x >= 0 && x + 1 < n && y >= 0 && y + 2 < m) {
        // ㅜ
        ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+1]);
    }
    if(x - 1 >= 0 && x + 1 < n && y >= 0 && y + 1 < m) {
        // ㅓ
        ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x+1][y+1] + arr[x-1][y+1]);
    }
    if(x - 1 >= 0 && x < n && y >= 0 && y + 2 < m) {
        // ㅗ
        ans = max(ans, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x-1][y+1]);
    }
    if(x >= 0 && x + 2 < n && y >= 0 && y + 1 < m) {
        // ㅏ
        ans = max(ans, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+1][y+1]);
    }
}

void solve(int x, int y, int length, int sum) {
    if(length == 4) {
        ans = max(ans, sum);
        return;
    }

    for(int i = 0; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        solve(nx, ny, length + 1, sum + arr[nx][ny]);
        visited[nx][ny] = 0; //대칭, 회전 위해서는 다시 방문해야함
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            // ㅜ 모양
            solve_shape(i, j);

            // 나머지 모양
            visited[i][j] = 1;
            solve(i, j, 1, arr[i][j]);
            visited[i][j] = 0; // 대칭, 회전 위해서는 다시 방문해야함
        }
    }

    cout << ans;

    return 0;
}