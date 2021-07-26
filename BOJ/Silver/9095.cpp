//BOJ 9095번: 1, 2, 3 더하기
//2021-05-28
//Dynamic programming
#include <iostream>
using namespace std;
int dp[11];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4 ; i < 11 ; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for(int i = 0 ; i < tc ; i++){
        int num;
        cin >> num;
        cout << dp[num] << '\n';
    }
    
    return 0;
}