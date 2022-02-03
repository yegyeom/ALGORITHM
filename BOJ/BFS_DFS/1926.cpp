/*
BOJ 1926번: 그림
DATE: 2022-02-03
DFS
*/
#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int n, m, maxVal = 0, cnt = 0;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;

    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(arr[nx][ny] && !visited[nx][ny]) dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num = 0;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(arr[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                num++;
                maxVal = max(maxVal, cnt);
                cnt = 0;
            }
        }
    }

    cout << num << '\n' << maxVal;

    return 0;
}