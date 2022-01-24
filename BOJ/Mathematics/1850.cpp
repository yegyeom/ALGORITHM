/*
BOJ 1850번: 최대공약수
DATE: 2022-01-24
Euclidean algorithm
*/
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long a, b;
    cin >> a >> b;
    
    for(int i = 0 ; i < gcd(a, b) ; i++) cout << 1;

    return 0;
}