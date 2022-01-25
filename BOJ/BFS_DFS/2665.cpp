/*
BOJ 2665번: 미로만들기
DATE: 2021-02-25
BFS
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 51
using namespace std;

int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1 , 0, -1};
int n;

void bfs(){
    queue<pair<int, int>> q;

    memset(visited, -1, sizeof(visited));
    q.push(make_pair(0, 0));
    visited[0][0] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny]){ //1
                if(visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y]){
                    visited[nx][ny] = visited[x][y];
                    q.push(make_pair(nx, ny));
                }
            }
            else if(nx >= 0 && nx < n && ny >= 0 && ny < n && !arr[nx][ny]){ //0
                 if(visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y] + 1){
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0 ; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0 ; j < n ; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

    bfs();

    cout << visited[n-1][n-1];
    
    return 0;
}