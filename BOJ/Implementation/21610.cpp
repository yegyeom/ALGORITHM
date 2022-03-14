/*
BOJ 21610번: 마법사 상어와 비바라기
DATE: 2022-03-14
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
int arr[51][51];
vector<pair<int,int>> cloud, mv_cloud;
int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diagonalR[4] = {-1, -1, 1, 1};
int diagonalC[4] = {-1, 1, 1, -1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int d, s;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> arr[i][j];
        }
    }

    cloud.push_back({n - 1, 1});
    cloud.push_back({n - 1, 2});
    cloud.push_back({n, 1});
    cloud.push_back({n, 2});

    for(int i = 0 ; i < m ; i++){
        cin >> d >> s;

        for(int j = 0 ; j < cloud.size() ; j++){ // 1번
            int r = cloud[j].first;
            int c = cloud[j].second;
            int nr, nc;

            for(int k = 0 ; k < s ; k++){
                if(r == 1 && r + dr[d - 1] == 0) nr = n;
                else if(r == n && r + dr[d - 1] == n + 1) nr = 1;
                else nr = r + dr[d - 1];

                if(c == 1 && c + dc[d - 1] == 0) nc = n;
                else if(c == n && c + dc[d - 1] == n + 1) nc = 1;
                else nc = c + dc[d - 1];

                r = nr;
                c = nc;
            }

            mv_cloud.push_back({r, c});
        }

        // 2번
        for(int j = 0 ; j < mv_cloud.size() ; j++) arr[mv_cloud[j].first][mv_cloud[j].second] += 1;

        // 4번
        for(int j = 0 ; j < mv_cloud.size() ; j++){
            int r = mv_cloud[j].first;
            int c = mv_cloud[j].second;
            int cnt = 0;

            for(int k = 0 ; k < 4 ; k++){
                int nr = r + diagonalR[k];
                int nc = c + diagonalC[k];

                if(nr == 0 || nc == 0 || nr == n + 1 || nc == n + 1) continue;
                if(arr[nr][nc] > 0) cnt++;
            }

            arr[r][c] += cnt;
        }

        cloud.clear();

        // 5번
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(arr[i][j] > 1) {
                    pair<int,int> p = {i, j};

                    if(find(mv_cloud.begin(), mv_cloud.end(), p) == mv_cloud.end()){
                        cloud.push_back({i, j});
                        arr[i][j] -= 2;
                    }
                }
            }
        }

        mv_cloud.clear();
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            ans += arr[i][j];
        }
    }

    cout << ans;

    return 0;
}