/*
BOJ 1094번: 막대기
DATE: 2022-01-25
Bitmask
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    cin >> n;

    for(int i = 0 ; i < 7 ; i++) {
        if(n & (1 << i)) ans++;
    }

    cout << ans;
    
    return 0;
}