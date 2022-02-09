/*
BOJ 16235번: 나무 재테크
DATE: 2022-02-09
Implementation
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;

int n, m, k;
int addition[MAX][MAX]; // 추가할 양분의 양
int nutrient[MAX][MAX]; // 해당 칸에 존재하는 양분의 양
vector<int> ground[MAX][MAX]; // 해당 칸에 존재하는 나무의 나이
vector<pair<pair<int,int>, int>> death; // 죽은 나무의 위치와 나이

void spring(){
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++){
            sort(ground[i][j].begin(), ground[i][j].end());

            for(int k = 0 ; k < ground[i][j].size() ; k++){
                if(nutrient[i][j] >= ground[i][j][k]) {
                    nutrient[i][j] -= ground[i][j][k];
                    ground[i][j][k] += 1;
                }
                else {
                    death.push_back({{i, j}, ground[i][j][k]});
                    ground[i][j].erase(ground[i][j].begin() + k);
                    k--;
                }
            }
        }
    }
}

void summer(){
    if(death.empty()) return;
    
    for(int i = 0 ; i < death.size() ; i++) {
        int x = death[i].first.first;
        int y = death[i].first.second;
        int add = death[i].second / 2;
        nutrient[x][y] += add;
    }

    death.clear();
}

void autumn(){ 
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++){
            for(int k = 0 ; k < ground[i][j].size() ; k++){
                if(ground[i][j][k] % 5 == 0) {
                    for(int l = 0 ; l < 8 ; l++) {
                        int nx = dx[l] + i;
                        int ny = dy[l] + j;

                        if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
                        ground[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
}

void winter(){
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            nutrient[i][j] += addition[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y, z;
    int ans = 0;

    cin >> n >> m >> k;

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            cin >> addition[i][j];
            nutrient[i][j] = 5;
        }
    }

    for(int i = 0 ; i < m ; i++) {
        cin >> x >> y >> z;
        ground[x][y].push_back(z);
    }

    while(k--){
        spring();
        summer();
        autumn();
        winter();
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++){
            ans += ground[i][j].size();
        }
    }

    cout << ans;

    return 0;
}