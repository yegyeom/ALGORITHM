/*
BOJ 2609번: 최대공약수와 최소공배수
DATE: 2022-01-24
Euclidean algorithm
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << '\n' << a * b / gcd(a, b);
    
    return 0;
}