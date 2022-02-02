/*
BOJ 11725번: 트리의 부모 찾기
DATE: 2022-02-02
DFS
*/
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int n;
int arr[MAX];

void dfs(int node) {
    for(int i = 0 ; i < graph[node].size() ; i++) {
        int nextNode = graph[node][i];

        if(!arr[nextNode]) {
            arr[nextNode] = node;
            dfs(nextNode);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> n;

    for(int i = 0 ; i < n - 1 ; i++) {
        cin >> a >> b; 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    for(int i = 2 ; i <= n ; i++) cout << arr[i] << '\n';

    return 0;
}