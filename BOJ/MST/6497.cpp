/*
BOJ 6497번: 전력난
2022-01-04
Kruskal Algorithm
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

int parent[MAX];
vector<pair<int,pair<int,int>>> edge;

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a == b) return 1;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, n;
    int x, y, z;

    while(1){
        cin >> m >> n;
        if(!m && !n) break;

        int sum = 0, ans = 0;

        edge.clear();
        for(int i = 1 ; i <= m ; i++) parent[i] = i;

        for(int i = 0 ; i < n ; i++) {
            cin >> x >> y >> z;
            edge.push_back({z, {x, y}});
            sum += z;
        }

        sort(edge.begin(), edge.end());

        for(int i = 0 ; i < edge.size() ; i++){
            int x = edge[i].second.first;
            int y = edge[i].second.second;
            int z = edge[i].first;

            if(findParent(x, y)) continue;
            unionParent(x, y);
            ans += z;
        }

        cout << sum - ans << '\n';
    }

    return 0;
}