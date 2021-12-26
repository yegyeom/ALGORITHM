/*
BOJ 1747번: 소수&팰린드롬
2021-12-26
*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;

    for(int i = 2 ; i <= sqrt(num) ; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

bool checkPalindrome(string str) {
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
    int n;
    cin >> n;

    for(int i = n ; ; i++) {
        if(isPrime(i) && checkPalindrome(to_string(i))){
            cout << i;
            break;
        }
    }

    return 0;
}