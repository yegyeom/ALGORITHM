/*
BOJ 14503번: 로봇 청소기
DATE: 2022-02-04
Implementation
*/
#include <iostream>
#include <queue>
using namespace std;

int n, m, ans;
int arr[51][51];
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1};
int x, y, d;

int getDir(int d) {
    if(d == 0) return 3;
    else if(d == 1) return 0;
    else if(d == 2) return 1;
    else return 2;
}

void solve(){
    while(1){
        bool flag = false;

        if(!arr[x][y]){
            arr[x][y] = 2; // 청소 완료
            ans++;
        }
        
        for(int i = 0 ; i < 4 ; i++) {
            d = getDir(d);
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny]) continue;
            
            x = nx;
            y = ny;
            flag = true;

            break;
        }

        if(!flag) { // 네 방향 모두 청소가 이미 되어있거나 벽인 경우
            int nd = (d + 2) % 4; // 후진 할 방향
            int nx = x + dx[nd];
            int ny = y + dy[nd];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(arr[nx][ny] != 1) { // 후진 가능 (방향은 그대로)
                x = nx;
                y = ny;
            }
            else return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> x >> y >> d;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }

    solve();
    cout << ans;

    return 0;
}