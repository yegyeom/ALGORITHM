#include <iostream>

using namespace std;
int arr[101][100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int w[101], v[101];

    for(int i = 1 ; i <= n ; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= k ; j++){
            if(w[i] > j) //기존의 최대 가치 유지
                arr[i][j] = arr[i-1][j]; 
            else{ //(i번째 물건을 담을 때, 담지 않을 때) max 값 선택
                arr[i][j] = max(v[i] + arr[i-1][j - w[i]], arr[i-1][j]);
            }
        }
    }

    cout << arr[n][k];

    return 0;
}