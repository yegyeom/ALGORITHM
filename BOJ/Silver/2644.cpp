//BOJ 2644번: 촌수계산
//2021-10-18
#include <iostream>
using namespace std;

int n, a, b, answer = -1;
int arr[100][100];
bool visited[100] = {false,};

void dfs(int node, int length) {
    visited[node] = true;

    for(int i = 1 ; i <= n ; i++) {
        if(arr[node][i] == 1 && !visited[i]) {
            if(i == b) {
                answer = length;
                return;
            }
            dfs(i, length + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin >> n >> a >> b >> m;

    for(int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }

    dfs(a, 1);
    cout << answer;

    return 0;
}