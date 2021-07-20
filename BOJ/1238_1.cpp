//BOJ 1238번: 파티
//Floyd Warshall Algorithm
//2021-07-12
#include <iostream>
#include <algorithm>
#define MAX 1000
#define INF 1e9
using namespace std;

int arr[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, x, start, end, t, maximum=-1;
    cin >> n >> m >> x;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i != j) arr[i][j] = INF;
        }
    }

    for(int i = 0 ; i < m ; i++){
        cin >> start >> end >> t;
        arr[start-1][end-1] = t;
    }

    for(int k = 0 ; k < n ; k++){ //거쳐가는 노드
        for(int i = 0 ; i < n ; i++){ //출발 노드
            for(int j = 0 ; j < n ; j++){ //도착 노드
                if(arr[i][k] + arr[k][j] < arr[i][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            } 
        }
    }
    
    int ans[n];

    for(int i = 0 ; i < n ; i++){
        ans[i] = arr[i][x-1] + arr[x-1][i];
        maximum = max(ans[i], maximum);
    }

    cout << maximum;

    return 0;
}