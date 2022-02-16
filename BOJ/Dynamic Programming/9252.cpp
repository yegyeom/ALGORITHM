/*
BOJ 9252번: LCS 2
DATE: 2022-02-16
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

    for(int i = 1 ; i <= str2.length() ; i++){
        for(int j = 1 ; j <= str1.length() ; j++){
            if(str2[i - 1] == str1[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
        }
    }

    int length = dp[str2.length()][str1.length()];
    cout << length << '\n';

    if(length == 0) return 0;
    
    char ans[length];
    int i = str2.length(), j = str1.length();
    int idx = 0, num = length;

     while(1){
        if(num == 0) break;

        if(num == dp[i][j - 1]) j--;
        else if(num == dp[i - 1][j]) i--;
        else {
            ans[idx++] = str1[j - 1];
            num = dp[i - 1][j - 1];
            i--; 
            j--;
        }
    }

    reverse(ans, ans + length);
    for(int i = 0 ; i < length ; i++) cout << ans[i];

    return 0;
}