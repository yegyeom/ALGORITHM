/*
BOJ 16236번: 아기 상어
DATE: 2021-04-11
BFS
*/
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
#define MAX 20
using namespace std;

int arr[MAX][MAX];
int n; 
int shark=2, eat, mv; //상어의 크기, 상어가 먹은 물고기 수, 상어가 움직인 횟수
bool visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

priority_queue<tuple<int, int, int>> pq;
//최소힙의 우선순위는 이동거리 - x좌표 - y좌표
//문제의 우선순위가 거리가 가까운 것 - 가장 위쪽 - 가장 왼쪽이기 때문에

void bfs(){
    tuple<int, int, int> t;

    while(!pq.empty()){
        t = pq.top();
        int d = -get<0>(t);
        int x = -get<1>(t);
        int y = -get<2>(t);
        pq.pop();

        if(0 < arr[x][y] && arr[x][y] < shark){ //해당 위치의 물고기를 먹을 수 있는 경우
            eat++;
            arr[x][y] = 0;
            if(shark == eat){ //상어의 크기 수만큼 물고기를 먹었을 때
                eat = 0;
                shark++;
            }

            mv += d;
            d = 0;
            memset(visited, false, sizeof(visited));
            while(!pq.empty()) pq.pop();
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] <= shark && !visited[nx][ny]){
                visited[nx][ny] = true;
                pq.push(make_tuple(-(d+1), -nx, -ny));
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                pq.push(make_tuple(0, -i, -j)); //우선순위 큐를 min heap으로 바꾸기 위해 음수 처리
                arr[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }

    bfs();
    cout << mv;
    
    return 0;
}