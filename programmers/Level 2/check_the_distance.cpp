/*
programmers Level 2: 거리두기 확인하기
2021-10-26
2021 카카오 채용연계형 인턴십
*/
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[5][5];
bool flag;
vector<string> place;

void dfs(int x, int y, int depth) {
    if(depth > 2) { 
        return;
    }
    
    visited[x][y] = true;
    
    for(int i = 0 ; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny] || place[nx][ny] == 'X') continue;
        if(place[nx][ny] == 'P' && depth < 2) { // 거리 2 이하에 사람 있으면 안됨
            flag = false;
            return;
        }
        dfs(nx, ny, depth + 1);
    }
}

bool func() {
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 5 ; j++) {
            if(place[i][j] == 'P') {
                flag = true;
                memset(visited, false, sizeof(visited));
                dfs(i, j, 0);
                if(!flag) return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    string str;
    
    for(int i = 0 ; i < 5 ; i++) {
        place.clear();
        
        for(int j = 0 ; j < 5 ; j++) {
            for(int k = 0 ; k < 5 ; k++) {
                str += places[i][j][k];
            }
            place.push_back(str);
            str.clear();
        }
        
        if(!func()) answer.push_back(0);
        else answer.push_back(1);
    }
    
    return answer;
}