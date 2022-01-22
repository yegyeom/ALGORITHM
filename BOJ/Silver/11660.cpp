/*
BOJ 11660번: 구간 합 구하기 5
DATE: 2022-01-22
Prefix Sum
*/
#include <iostream>
using namespace std;

int arr[1025][1026];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, ans = 0;
    int x1, y1, x2, y2;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        ans = 0;
        for(int i = x1 ; i <= x2 ; i++) ans += arr[i][y2] - arr[i][y1 - 1];

        cout << ans << '\n';
    }

    return 0;
}