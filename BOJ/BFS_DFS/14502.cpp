/*
BOJ 14502번: 연구소
DATE: 2021-10-07
UPDATE: 2022-04-03
BFS
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX 8
using namespace std;

vector<pair<int, int>> virus, candidate;
int n, m, ans = -1;
int arr[MAX][MAX], tmp[MAX][MAX], visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] == 1) continue;
            if(tmp[nx][ny] == 1) continue;

            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
            tmp[nx][ny] = 2;
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) virus.push_back(make_pair(i, j));
            else if(arr[i][j] == 0) candidate.push_back(make_pair(i, j));
        }
    }

    vector<bool> idx(candidate.size(), false);

    for(int i = 0 ; i < 3 ; i++) idx[i] = true;
    sort(idx.begin(), idx.end());

    do{
        int cnt = 0;

        memcpy(tmp, arr, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for(int i = 0 ; i < idx.size() ; i++){
            if(idx[i]) tmp[candidate[i].first][candidate[i].second] = 1; //벽 설치
        }

        for(int i = 0 ; i < virus.size() ; i++) {
            bfs(virus[i].first, virus[i].second); //바이러스 위치에서 bfs 시작
        }

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(tmp[i][j] == 0) cnt++; //안전 영역 수
            }
        }

        ans = max(cnt, ans); 
    }while(next_permutation(idx.begin(), idx.end()));
    
    cout << ans;

    return 0;
}