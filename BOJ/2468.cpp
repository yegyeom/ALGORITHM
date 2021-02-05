#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int area[MAX][MAX];
int tmp[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;

void dfs(int x, int y){
    tmp[x][y] = 0;
    
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && tmp[nx][ny] == 1)
            dfs(nx, ny);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = -1, max_value = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> area[i][j];
            max_value = max(area[i][j], max_value);
        }
    }

    memcpy(tmp, area, sizeof(area));

    for(int k = 0 ; k < max_value ; k++){
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(area[i][j] <= k){
                    tmp[i][j] = 0;
                }
                else tmp[i][j] = 1;
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(tmp[i][j] == 1){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        
        memcpy(tmp, area, sizeof(area));
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}