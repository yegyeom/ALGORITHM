/*
BOJ 1647번: 도시 분할 계획
2021-12-29
Kruskal Algorithm
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

pair<int, pair<int,int>> edge[MAX];

int getParent(int parent[], int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return 1;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int n, m;
    int a, b, c;
    int ans = 0, cnt = 0;
    cin >> n >> m;

    int parent[n + 1];
    for(int i = 1 ; i <= n ; i++) parent[i] = i;

    for(int i = 0 ; i < m ; i++) {
        cin >> a >> b >> c;
        edge[i].first = c; 
        edge[i].second.first = a;
        edge[i].second.second = b;
    }

    sort(edge, edge + m);

    for(int i = 0 ; i < m ; i++) {
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        int c = edge[i].first;

        if(findParent(parent, a, b)) continue;
        
        unionParent(parent, a, b);
        ans += c;
        if(++cnt == n - 2) break;
    }

    cout << ans;

    return 0;
}