/*
BOJ 1003번: 피보나치 함수
DATE: 2021-05-28
Dynamic programming
*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cnt0[41]={0,}, cnt1[41]={0,};
    int tc;
    cin >> tc;

    cnt0[0] = 1;
    cnt1[1] = 1;

    for(int i = 2 ; i <= 40 ; i++){
        cnt0[i] = cnt0[i - 2] + cnt0[i - 1];
        cnt1[i] = cnt1[i - 2] + cnt1[i - 1];
    }

    for(int i = 0 ; i < tc ; i++){
        int n;
        cin >> n;
        cout << cnt0[n] << " " << cnt1[n] << '\n';
    }

    return 0;
}