/*
BOJ 2231번: 분해합
2021-05-18
Brute Force
*/
#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int f(int num){
    int sum = num;

    while (num != 0) {
		sum += num % 10;
		num = num / 10;
	}

	return sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = 1 ; i < n ; i++){
        int num = f(i);

        if(num == n){
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}