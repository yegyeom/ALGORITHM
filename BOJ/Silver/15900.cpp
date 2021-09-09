//BOJ 15900번: 나무 탈출
//2021-09-10
#include <iostream>
#include <vector>
#define MAX 500001
using namespace std;

int n, total=0;
vector<int> v[MAX];
int visited[MAX];

void dfs(int node, int depth){
    visited[node] = true;

    if(node != 1 && v[node].size() == 1){ //leaf node
        total += depth;
    }
    else {
        for(int i = 0 ; i < v[node].size() ; i++){
            if(!visited[v[node][i]]){
                dfs(v[node][i], depth + 1);
                visited[v[node][i]] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> n;

    for(int i = 0 ; i < n - 1 ; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0);

    if(total % 2 == 0) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}