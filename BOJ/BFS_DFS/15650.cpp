/*
BOJ 15650번: N과 M (2)
2022-01-06
Backtracking
*/
#include <iostream>
#define MAX 8
using namespace std;

int n, m;
int arr[MAX]; 
bool visited[MAX]; 

void dfs(int num, int cnt){
    if(cnt == m) {
        for(int i = 0 ; i < m ; i++) cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = num ; i <= n ; i++){
        if(visited[i]) continue;

        arr[cnt] = i;
        visited[i] = true;
        dfs(i + 1, cnt + 1);
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    dfs(1, 0);

    return 0;
}