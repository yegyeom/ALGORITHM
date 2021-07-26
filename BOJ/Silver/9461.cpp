//BOJ 9461번: 파도반 수열
//2021-05-28
//Dynamic programming
#include <iostream>
#define MAX 101
using namespace std;
long long dp[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;

    dp[1] = dp[2] = dp[3] = 1;

    for(int i = 4 ; i < MAX ; i++){
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    for(int i = 0 ; i < tc ; i++){
        int num;
        cin >> num;
        cout << dp[num] << '\n';
    }
    
    return 0;
}