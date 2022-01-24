/*
BOJ 4386번: 별자리 만들기
2021-12-29
Kruskal Algorithm
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 101
using namespace std;

vector<pair<double, double>> coordinate;
vector<pair<double, pair<double, double>>> edge;
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
    double ans = 0;
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        double x, y;
        cin >> x >> y;
        coordinate.push_back({x, y});
    }

    for(int i = 0 ; i < coordinate.size() ; i++) {
        double x_a = coordinate[i].first;
        double y_a = coordinate[i].second;

        for(int j = i + 1 ; j < coordinate.size() ; j++){
            double x_b = coordinate[j].first;
            double y_b = coordinate[j].second;
            
            double distance = sqrt(pow((x_b - x_a), 2) + pow((y_b - y_a), 2));
            edge.push_back({distance, {i + 1, j + 1}});
        }
    }

    sort(edge.begin(), edge.end());
    for(int i = 1 ; i <= n ; i++) parent[i] = i;

    for(int i = 0 ; i < edge.size() ; i++) {
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        double c = edge[i].first;

        if(findParent(a, b)) continue;
        unionParent(a, b);
        ans += c;
    }

    cout << ans;

    return 0;
}