/*
BOJ 1735번: 분수 합
DATE: 2022-03-16
*/
#include <iostream>
using namespace std;

int gcd(int n, int m){
    if(m == 0) return n;
    else return gcd(m, n % m);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d;
    int n, m;
    
    cin >> a >> b >> c >> d;
    
    n = a * d + b * c;
    m = b * d;

    int div = gcd(n, m);

    cout << n / div << " " << m / div;
    
    return 0;
}