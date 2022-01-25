/*
BOJ 14502번: 연구소
DATE: 2021-10-07
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
pair<int, int> cArr[3];

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

void combination(int depth, int next) { //n: candidate 크기, r: 3
    if (depth == 3) { //조합 완료
        int cnt = 0;
        memcpy(tmp, arr, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for(int i = 0 ; i < 3 ; i++) {
                tmp[cArr[i].first][cArr[i].second] = 1; //벽 설치
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
        
        return;
    }

    for(int i = next ; i <= candidate.size() ; i++) {
        cArr[depth] = candidate[i - 1];
        combination(depth + 1, i + 1);
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

    combination(0, 1); //설치 가능한 벽들의 조합
    cout << ans;

    return 0;
}