/*
BOJ 6219번: 소수의 자격
2022-01-20
*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, d;
    int ans = 0;
    
    cin >> a >> b >> d;

    int prime[b + 1];
    char ch = d + '0';

    for(int i = 2 ; i <= b ; i++) prime[i] = i;

    for(int i = 2 ; i <= sqrt(b) ; i++){
        if(prime[i] == 0) continue;
        for(int j = i * i ; j <= b ; j += i) prime[j] = 0;
    }

    for(int i = a ; i <= b ; i++) {
        string str = to_string(prime[i]);
        if(prime[i] != 0 && find(str.begin(), str.end(), ch) != str.end()) ans++;
    }

    cout << ans;
    
    return 0;
}