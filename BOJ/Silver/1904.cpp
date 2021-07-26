//BOJ 1904번: 01타일
//2021-05-28
//Dynamic programming
#include <iostream>
#define MOD 15746
#define MAX 1000001
using namespace std;

long long dp[MAX] = {0,};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3 ; i <= n ; i++){
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }

   cout << dp[n];

    return 0;
}