/*
BOJ 2887번: 행성 터널
2022-01-04
Kruskal Algorithm
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

vector<pair<int,int>> c_x, c_y, c_z;
vector<pair<int, pair<int,int>>> edge;
int parent[MAX];

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
    int n;
    int x, y, z;
    int ans = 0;
    cin >> n;

    vector<int> c(n);

    for(int i = 0 ; i < n ; i++) {
        cin >> x >> y >> z;
        c_x.push_back({x, i});
        c_y.push_back({y, i});
        c_z.push_back({z, i});
    }

    sort(c_x.begin(), c_x.end());
    sort(c_y.begin(), c_y.end());
    sort(c_z.begin(), c_z.end());

    for(int i = 1 ; i < n ; i++) {
        edge.push_back({abs(c_x[i - 1].first - c_x[i].first), {c_x[i - 1].second, c_x[i].second}});
        edge.push_back({abs(c_y[i - 1].first - c_y[i].first), {c_y[i - 1].second, c_y[i].second}});
        edge.push_back({abs(c_z[i - 1].first - c_z[i].first), {c_z[i - 1].second, c_z[i].second}});
    }

    sort(edge.begin(), edge.end());
    for(int i = 1 ; i <= n ; i++) parent[i] = i;

    for(int i = 0 ; i < edge.size() ; i++) {
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        int c = edge[i].first;

        if(findParent(a, b)) continue;
        unionParent(a, b);
        ans += c;
    }

    cout << ans;

    return 0;
}