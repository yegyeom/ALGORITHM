#include <iostream>
#define INF 1e9
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b, ans=0;
    cin >> n >> m;
    
    int arr[n+1][n+1];

    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1 ; j < n+1 ; j++){
            if(i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        arr[a][b] = 1;
    }

    for(int k = 1 ; k <= n ; k++){ //거쳐가는 노드
        for(int i = 1 ; i <= n ; i++){ //출발 노드
            for(int j = 1 ; j <= n ; j++){ //도착노드
                if(arr[i][k] + arr[k][j] < arr[i][j]){
                    arr[i][j] = 1;
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        int cnt = 0;
        for(int j = 1 ; j <= n ; j++){
            if(arr[i][j] == 1 || arr[j][i] ==1)
                cnt++;
        }
        if(cnt == n - 1) ans++;
    }

    cout << ans;

    return 0;
}