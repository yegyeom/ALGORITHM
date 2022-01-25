/*
BOJ 11724번: 연결 요소의 개수
DATE: 2021-05-25
DFS, BFS
*/
#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int n, m, cnt=0;
int arr[MAX][MAX];
bool visited[MAX];

void bfs(int num){
    queue<int> q;
    visited[num] = true;
    q.push(num);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int i = 1 ; i <= n ; i++){
            if(arr[front][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs(int num){
    visited[num] = true;

    for(int i = 1 ; i <= n ; i++){
        if(arr[num][i] && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int num1, num2;
        cin >> num1 >> num2;
        arr[num1][num2] = arr[num2][num1] = 1;
    }

    for(int j = 1 ; j <= n ; j++){
        if(!visited[j]){
            cnt++;
            bfs(j);
            //or
            //dfs(j);
        }
    }

    cout << cnt;

    return 0;
}