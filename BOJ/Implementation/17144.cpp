/*
BOJ 17144번: 미세먼지 안녕!
DATE: 2022-03-15
*/
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 51
using namespace std;

int arr[MAX][MAX], tmp[MAX][MAX];
int up, down;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int r, c, t;
vector<pair<int,int>> dust;

void spread(){
    for(int i = 0 ; i < dust.size() ; i++){
        int row = dust[i].first;
        int col = dust[i].second;
        int value = arr[row][col];
        int cnt = 0;

        for(int j = 0 ; j < 4 ; j++){
            int nr = row + dr[j];
            int nc = col + dc[j];

            if(nr < 1 || nc < 1 || nr > r || nc > c) continue;
            if(arr[nr][nc] == -1) continue;

            tmp[nr][nc] += value / 5;
            cnt++;
        }
            
        tmp[row][col] += value - (value / 5) * cnt;
    }
}

void upside(){ // 반시계 방향
    int a, b = 0;

    for(int i = 2 ; i <= c ; i++){
        a = tmp[up][i];
        tmp[up][i] = b;
        b = a;
    }

    for(int i = up - 1 ; i >= 1 ; i--){
        a = tmp[i][c];
        tmp[i][c] = b;
        b = a;
    }

    for(int i = c - 1 ; i >= 1 ; i--){
        a = tmp[1][i];
        tmp[1][i] = b;
        b = a;
    }

    for(int i = 2 ; i <= up ; i++){
        a = tmp[i][1];
        tmp[i][1] = b;
        b = a;
    }
}

void downside(){ // 시계 방향
    int a, b = 0;

    for(int i = 2 ; i <= c ; i++){
        a = tmp[down][i];
        tmp[down][i] = b;
        b = a;
    }

    for(int i = down + 1 ; i <= r ; i++){
        a = tmp[i][c];
        tmp[i][c] = b;
        b = a;
    }

    for(int i = c - 1 ; i >= 1 ; i--){
        a = tmp[r][i];
        tmp[r][i] = b;
        b = a;
    }

    for(int i = r - 1 ; i >= down ; i--){
        a = tmp[i][1];
        tmp[i][1] = b;
        b = a;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    cin >> r >> c >> t;

    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1){
                if(up == 0) up = i;
                else down = i;
            }
            else if(arr[i][j] > 0) dust.push_back({i,j});
        }
    }

    while(t--){
        memset(tmp, 0, sizeof(tmp));

        // 미세먼지 확산
        spread();

        // 공기청정기 작동
        upside();
        downside();

        dust.clear();

        for(int i = 1 ; i <= r ; i++){
            for(int j = 1 ; j <= c ; j++){
                if(arr[i][j] == -1) continue;
                arr[i][j] = tmp[i][j];
                dust.push_back({i, j});
            }
        }
    }

    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c ; j++){
            if(arr[i][j] > 0) ans += arr[i][j];
        }
    }

    cout << ans;

    return 0;
}