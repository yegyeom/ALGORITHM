/*
BOJ 7562번: 나이트의 이동
DATE: 2021-01-25
BFS
*/
#include <iostream>
#include <queue>
#include <string.h>
#define MAX 300

using namespace std;
int chess[MAX][MAX];
//시계 반대 방향
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int l, str_x, str_y, dst_x, dst_y;

void bfs() {
    queue<pair<int, int>> q;
    pair<int, int> p;

    q.push(make_pair(str_x, str_y));

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p.first == dst_x && p.second == dst_y) {
            cout << chess[dst_x][dst_y] - 1 << "\n";
            break;
        }

        for (int i = 0; i < 8; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
        
            if(nx < 0 || ny < 0 || nx >= l || ny >= l)
                continue;
            if (nx >= 0 && ny >= 0 && nx < l && ny < l && !chess[nx][ny]) {
                q.push(make_pair(nx, ny));
                chess[nx][ny] = chess[p.first][p.second] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> l;
        cin >> str_x >> str_y;
        cin >> dst_x >> dst_y;

        memset(chess, 0, sizeof(chess));
        chess[str_x][str_y] = 1;
        
        bfs();
    }

    return 0;
}