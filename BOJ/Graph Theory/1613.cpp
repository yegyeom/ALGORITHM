/*
BOJ 1613번: 역사
DATE: 2022-03-07
Floyd-Warshall Algorithm
*/
#include <iostream>
#define MAX 401
#define INF 1e9
using namespace std;

int arr[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, s;
    int a, b;

    cin >> n >> k;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j) continue;
            arr[i][j] = INF;
        }
    }

    for(int i = 0 ; i < k ; i++){
        cin >> a >> b; 
        arr[a][b] = 1; // a가 b보다 먼저 일어남
    }

    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = 1;
            }
        }
    }
    
    cin >> s;

    for(int i = 0 ; i < s ; i++){
        cin >> a >> b;

        if(arr[a][b] == INF && arr[b][a] == INF) cout << 0 << '\n'; // 순서 알 수 없음
        else if(arr[a][b] == 1 && arr[b][a] == INF) cout << -1 << '\n'; // 앞 번호 사건이 먼저 일어남
        else if(arr[a][b] == INF && arr[b][a] == 1) cout << 1 << '\n'; // 뒷 번호 사건이 먼저 일어남
    }

    return 0;
}