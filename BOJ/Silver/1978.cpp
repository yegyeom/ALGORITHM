//BOJ 1978번: 소수 찾기
//2021-10-09
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;

    for(int i = 2 ; i <= sqrt(num) ; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num, cnt = 0;
    vector<int> v;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        if(isPrime(num)) cnt++;
    }

    cout << cnt;

    return 0;
}