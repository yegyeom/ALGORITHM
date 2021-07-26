//BOJ 1197번: 최소 스패닝 트리
//Kruskal Algorithm
//2021-07-12
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

int v, e, a, b, c, ans=0;
pair<int, pair<int, int>> edge[MAX];

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
    cin >> v >> e;
    int parent[v+1];

    for(int i = 1 ; i <= v ; i++){
        parent[i] = i;
    }

    for(int i = 0 ; i < e ; i++){
        cin >> a >> b >> c;
        edge[i].first = c;
        edge[i].second.first = a;
        edge[i].second.second = b;
    }    

    sort(edge, edge + e);

    for(int i = 0 ; i < e ; i++){
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