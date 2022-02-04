/*
BOJ 14889번: 스타트와 링크
DATE: 2022-02-04
Backtracking
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, minVal = 1e9;
int arr[21][21];
bool visited[21]; // 팀 배정

void dfs(int cnt, int num) {
    if(cnt == n / 2) {
        int start = 0, link = 0;

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                if(visited[i] && visited[j]) start += arr[i][j];
                else if(!visited[i] && !visited[j]) link += arr[i][j];
            }
        }

        minVal = min(minVal, abs(start - link));

        return;
    }

    for(int i = num ; i < n ; i++) { // n을 포함하면 중복 발생
        if(visited[i]) continue;

        visited[i] = true;
        dfs(cnt + 1, i + 1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0, 1); 
    cout << minVal;

    return 0;
}