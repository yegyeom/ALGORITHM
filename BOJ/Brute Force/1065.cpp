/*
BOJ 1065번: 한수
2021-05-18
Brute Force
*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans=0;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        if(i < 100){
            ans++;
            continue;
        }
        else{
            int n1 = i % 10; // 일의 자리
            int n2 = (i / 10) % 10; // 십의 자리
            int n3 = i / 100; // 십의 자리

            if(n3 - n2 == n2 - n1){
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}