/*
BOJ 15965번: K번째 소수
2022-01-29
*/
#include <iostream>
#include <math.h>
#define MAX 7400000
using namespace std;

int isNotPrime[MAX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, cnt = 0;
    cin >> k;

    for(int i = 2 ; i <= sqrt(MAX) ; i++) {
        if(!isNotPrime[i]) {
            for(int j = i * i ; j <= MAX ; j += i) isNotPrime[j] = 1;
        }
    }

    for(int i = 2 ; i <= MAX ; i++) {
        if(!isNotPrime[i]) {
            cnt++;

            if(cnt == k) {
                cout << i;
                break;
            }
        }
    }


    return 0;
}