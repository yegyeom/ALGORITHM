//BOJ 1922번: 네트워크 연결
//Kruskal Algorithm
//2021-07-12
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a, b, c, ans=0;
pair<int, pair<int, int>> edge[100000];

int getParent(int parent[], int x){
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int parent[n+1];

    for(int i = 1 ; i <= n ; i++){
        parent[i] = i;
    }

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> c;
        edge[i].first = c;
        edge[i].second.first = a;
        edge[i].second.second = b;
    }

    sort(edge, edge + m);

    for(int i = 0 ; i < m ; i++){
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        int c = edge[i].first;

        if(findParent(parent, a, b)) continue;
        else{
            unionParent(parent, a, b);
            ans += c;
        }
    }

    cout << ans;

    return 0;
}