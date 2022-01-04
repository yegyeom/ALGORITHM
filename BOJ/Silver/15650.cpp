/*
BOJ 15650번: N과 M (2)
2022-01-04
Backtracking
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int n, m;
int arr[MAX]; 
vector<int> num; 
vector<vector<int>> ans;
bool visited[MAX]; 

void dfs(int cnt){
    if(cnt == m) {
        vector<int> tmp = num;
    
        sort(tmp.begin(), tmp.end());
        ans.push_back(tmp);

        return;
    }

    for(int i = 0 ; i < n ; i++){
        if(visited[i]) continue;

        num.push_back(arr[i]);
        visited[i] = true;

        dfs(cnt + 1);
        
        num.pop_back();
        visited[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++) arr[i] = i + 1;

    dfs(0);
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end()); // 중복 제거

    for(int i = 0 ; i < ans.size() ; i++){
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}