/*
BOJ 1956번: 운동
DATE: 2022-03-04
Floyd-Warshall Algorithm
*/
#include <iostream>
#include <algorithm>
#define MAX 401
#define INF 1e9
using namespace std;

int arr[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v, e;
    int a, b, c;
    int minVal = INF;
    cin >> v >> e;

    fill(&arr[0][0], &arr[v][v], INF);

    for(int i = 0 ; i < e ; i++){
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    for(int k = 1 ; k <= v ; k++){
        for(int i = 1 ; i <= v ; i++){
            for(int j = 1 ; j <= v ; j++){
                if(arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    for(int i = 1 ; i <= v ; i++){
        for(int j = 1 ; j <= v ; j++){
            if(i == j || arr[i][j] == INF) continue;
            minVal = min(minVal, arr[i][j] + arr[j][i]);
        }
    }

    if(minVal == INF) cout << -1;
    else cout << minVal;

    return 0;
}