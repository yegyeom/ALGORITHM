/*
BOJ 3190번: 뱀
DATE: 2022-03-24
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int n;
int board[MAX][MAX]; // 0: 빈 칸, 1: 뱀, -1: 사과 
vector<pair<int, char>> rotation;
vector<pair<int,int>> snake;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool check_range(int r, int c){
    if(r < 1 || c < 1 || r > n || c > n) return false; // 벽에 부딪힌 경우
    if(board[r][c] == 1) return false; // 몸에 부딪히는 경우
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, l;
    int r, c, x;
    char ch;

    cin >> n >> k;

    int hr = 1, hc = 1;
    int dir = 0;

    board[1][1] = 1;
    snake.push_back({1, 1});

    while(k--){
        cin >> r >> c;
        board[r][c] = -1;
    }

    cin >> l;

    while(l--){
        cin >> x >> ch;
        rotation.push_back({x, ch});
    }

    sort(rotation.begin(), rotation.end());

    int sec = 1;

    while(1){
        bool apple = false;

        // 1. 머리 다음칸으로 이동
        int new_hr = hr + dr[dir];
        int new_hc = hc + dc[dir];

        if(!check_range(new_hr, new_hc)) break; // 종료
        if(board[new_hr][new_hc] == -1) apple = true; // 이동한 칸에 사과 존재

        board[new_hr][new_hc] = 1;
        snake.insert(snake.begin(), {new_hr, new_hc}); // 바뀐 머리 위치 삽입
        hr = new_hr;
        hc = new_hc;

        // 2. 이동한 칸에 사과 없는 경우 => 꼬리 위치한 칸 비워줌
        if(!apple) {
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        
        // 3. 방향 회전
        if(rotation.front().first == sec){
            if(rotation.front().second == 'D'){
                if(dir == 3) dir = 0;
                else dir += 1;
            }
            else{ 
                if(dir == 0) dir = 3;
                else dir -= 1;
            }

            rotation.erase(rotation.begin());
        }

        sec++;
    }

    cout << sec;

    return 0;
}