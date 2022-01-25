/*
BOJ 9184번: 신나는 함수 실행
DATE: 2021-05-28
Dynamic programming
*/
#include <iostream>
using namespace std;
int dp[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    else if(a < b && b < c){
        if(dp[a][b][c] != 0)
            return dp[a][b][c];
        else
            return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else{
        if(dp[a][b][c] != 0)
            return dp[a][b][c];
        else
            return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1)
            break;
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }

    return 0;
}