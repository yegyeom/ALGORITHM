//BOJ 2747번: 피보나치 수
//2021-07-06
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long dp[46];
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2 ; i < n+1 ; i++){
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout << dp[n];
    
    return 0;
}