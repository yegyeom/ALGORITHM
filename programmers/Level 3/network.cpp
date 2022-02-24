/*
programmers Level 3: 네트워크
2022-02-24
DFS
*/
#include <string>
#include <vector>
#define MAX 200
using namespace std;

vector<vector<int>> cp;
bool visited[MAX];

void dfs(int num, int n){
    visited[num] = true;
    
    for(int i = 0 ; i < n ; i++) {
        if(cp[num][i] && !visited[i]) dfs(i, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    cp = computers;
    
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]) {
            answer++;
            dfs(i, n);
        }
    }
    
    return answer;
}