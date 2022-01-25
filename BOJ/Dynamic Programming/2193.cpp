/*
BOJ 2193번: 이친수
DATE: 2021-05-28
Dynamic programming
*/
#include <iostream>
#define MAX 91
using namespace std;

long long dp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    dp[1] = dp[2] = 1;

    for(int i = 3 ; i < MAX ; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << '\n';
    
    return 0;
}