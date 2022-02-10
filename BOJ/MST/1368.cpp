/*
BOJ 1368번: 물대기
DATE: 2022-02-11
Kruskal Algorithm
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 301
using namespace std;

vector<pair<int,pair<int,int>>> edge;
int parent[MAX];

int getParent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if(a == b) return 1;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, input, ans = 0;
    cin >> n;

    for(int i = 1 ; i <= n ; i++) {
        cin >> input; // i번째 논에 우물을 팔 때 드는 비용
        edge.push_back({input, {0, i}}); // 0번 노드: 가상 노드
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            cin >> input; // i번째 논과 j번째 논을 연결하는데 드는 비용
            if(input == 0) continue;
            edge.push_back({input, {i, j}});
        }
    }

    for(int i = 0 ; i <= n ; i++) parent[i] = i;

    sort(edge.begin(), edge.end());

    for(int i = 0 ; i < edge.size() ; i++) {
        int x = edge[i].second.first;
        int y = edge[i].second.second;
        int z = edge[i].first;

        if(!findParent(x, y)) {
            unionParent(x, y);
            ans += z;
        }
    }

    cout << ans;

    return 0;
}