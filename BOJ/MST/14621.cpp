/*
BOJ 14621번: 나만 안되는 연애
DATE: 2022-03-03
Kruskal Algorithm
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

char gender[MAX];
vector<pair<int, pair<int,int>>> edge;
int parent[MAX];

int getParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

int findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a == b) return 1;
    else return 0;
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, ans = 0, cnt = 0;
    int a, b, c;
    char ch;

    cin >> n >> m;
    
    for(int i = 1 ; i <= n ; i++) cin >> gender[i];

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    sort(edge.begin(), edge.end());

    for(int i = 1 ; i <= n ; i++) parent[i] = i;

    for(int i = 0 ; i < edge.size() ; i++){
        int x = edge[i].second.first;
        int y = edge[i].second.second;
        int z = edge[i].first;

        if(gender[x] != gender[y] && !findParent(x, y)){
            unionParent(x, y);
            ans += z;
            cnt++;
        }
    }

    if(cnt < n - 1) cout << -1;
    else cout << ans;

    return 0;
}