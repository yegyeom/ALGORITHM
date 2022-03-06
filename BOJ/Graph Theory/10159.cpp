/*
BOJ 10159번: 저울
DATE: 2022-03-06
Floyd-Warshall Algorithm
*/
#include <iostream>
#define MAX 101
#define INF 1e9
using namespace std;

int arr[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int a, b, cnt = 0;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i != j) arr[i][j] = INF; 
        }
    }

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        arr[a][b] = 1;
    }

    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = 1;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(arr[i][j] == INF && arr[j][i] == INF) cnt++;
         }
         cout << cnt << '\n';
         cnt = 0;
    }

    return 0;
}