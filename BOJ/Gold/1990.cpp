/*
BOJ 1990번: 소수인팰린드롬
2021-12-26
*/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if(num < 2) return false;

    for(int i = 2 ; i <= sqrt(num) ; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

bool isPalindrome(string str) {
    string front, back;
    int length = str.length();

    front = str.substr(0, length / 2);

    if(length % 2 == 0) back = str.substr(length / 2);
    else back = str.substr(length / 2 + 1);

    reverse(back.begin(), back.end());

    if(front == back) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int a, b;
    cin >> a >> b;

    for(int i = a ; i <= 10000000 ; i++) {
        if(i > b) break;
        if(isPalindrome(to_string(i)) && isPrime(i)) {
            cout << i << '\n';
        }
    }

    cout << -1;

    return 0;
}