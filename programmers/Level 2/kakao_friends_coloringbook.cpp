//programmers Level 2 : KAKAO friends coloring book
//2017 KAKAO CODE
//2021-05-26
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 101
using namespace std;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int cnt, area, r, c;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y){
    int n = arr[x][y];
    arr[x][y] = 0;
    cnt++;
    
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= r || ny >= c || visited[nx][ny])
            continue;
        if(arr[nx][ny] == n){
            dfs(nx, ny);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    vector<int> v;
    
    cnt = area = 0;
    r = m;
    c = n;

    for(int i = 0 ; i < MAX ; i++){
        for(int j = 0 ; j < MAX ; j++){
            arr[i][j] = visited[i][j] = 0;
            
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            arr[i][j] = picture[i][j];
        }
    } 
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(arr[i][j] != 0){
                cnt = 0;
                dfs(i, j);
                area++;
                v.push_back(cnt);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    answer[0] = number_of_area = area;
    answer[1] = max_size_of_one_area = v[v.size() - 1];
    return answer;
}

int main(){
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}};
    
    vector <int> answer = solution(6, 4, picture);

    for(int i = 0 ; i < answer.size() ; i++){
        cout << answer[i] << " ";
    }

    return 0;
}