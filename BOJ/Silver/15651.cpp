/*
BOJ 15651번: N과 M (3)
2022-01-05
Backtracking
*/
#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int n, m;
vector<int> num;
vector<int> ans; 

void print(){
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << " ";
    cout << '\n';
}

void dfs(int cnt){
    if(cnt == m) {
        print();
        return;
    }

    for(int i = 0 ; i < n ; i++){
        ans.push_back(num[i]);
        dfs(cnt + 1);
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++) num.push_back(i + 1);
    dfs(0);

    return 0;
}