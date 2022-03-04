/*
BOJ 11404번: 플로이드
DATE: 2021-04-12
UPDATE: 2022-03-04
Floyd-Warshall Algorithm
*/
#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    int arr[n+1][n+1];
    fill(&arr[0][0], &arr[n][n + 1], INF);

    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    for(int k = 1 ; k <= n ; k++){ //거쳐가는 노드
        for(int i = 1 ; i <= n ; i++){ //출발 노드
            for(int j = 1 ; j <= n ; j++){ //도착 노드
                if(arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j || arr[i][j] == INF) cout << 0 << " ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}