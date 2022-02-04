/*
BOJ 1182번: 부분수열의 합
DATE: 2022-02-04
Backtracking
*/
#include <iostream>
using namespace std;

int n, s, ans;
int arr[21];
bool visited[21];

void dfs(int num) {
    int sum = 0;

    for(int i = 1 ; i <= n ; i++) {
        if(visited[i]) sum += arr[i];
    }

    if(sum == s) ans++;

    for(int i = num ; i <= n ; i++) {
        if(visited[i]) continue;

        visited[i] = true;
        dfs(i + 1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;

    for(int i = 1 ; i <= n ; i++) cin >> arr[i];

    dfs(1);
    if(s == 0) ans--;
    
    cout << ans;

    return 0;
}