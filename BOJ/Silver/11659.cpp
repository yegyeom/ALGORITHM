/*
BOJ 11659번: 구간 합 구하기 4
DATE: 2022-01-21
Prefix Sum
*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int a, b;
    cin >> n >> m;

    int arr[n + 1] = {0, };

    for(int i = 1 ; i <= n ; i++) cin >> arr[i];
    for(int i = 1 ; i <= n ; i++) arr[i] = arr[i - 1] + arr[i];

    for(int i = 0 ; i < m ; i++) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }

    return 0;
}