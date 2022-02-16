/*
BOJ 9251번: LCS
DATE: 2021-08-01
Dynamic Programming (Longest Common Subsequence)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    string str1, str2;
    cin >> str1 >> str2;

    for(int i = 1 ; i <= str2.size() ; i++){
        for(int j = 1 ; j <= str1.size() ; j++){
            if(str2[i-1] == str1[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else if(str2[i-1] != str1[j-1]) dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout << dp[str2.length()][str1.length()];

    return 0;
}