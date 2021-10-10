//BOJ 1929번: 소수 구하기
//2021-10-10
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[1000001];
    int m, n;
    cin >> m >> n;

    for(int i = 2 ; i <= n ; i++) {
        arr[i] = i;
    }

    for(int i = 2 ; i <= sqrt(n) ; i++) {
        if(arr[i] == 0) continue; //이미 소수가 아님

        for(int j = i * i ; j <= n ; j += i) arr[j] = 0;
    }

    for(int i = m ; i <= n ; i++) {
        if(arr[i] != 0) cout << arr[i] << '\n';
    }

    return 0;
}