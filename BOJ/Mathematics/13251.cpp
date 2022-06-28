/*
BOJ 13251번: 조약돌 꺼내기
DATE: 2022-06-28
*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, k, sum = 0;
    double ans = 0;

    cin >> m;
    
    int arr[m];
    
    for(int i = 0 ; i < m ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cin >> k;

    for(int i = 0 ; i < m ; i++){
        double a = 1, b = 1;

        for(int j = 0 ; j < k ; j++) {
            a *= arr[i] - j;
            b *= sum - j;
        }

        ans += (double)a / b;
    }

    cout << fixed;
    cout.precision(20);
    cout << ans;

    return 0;
}