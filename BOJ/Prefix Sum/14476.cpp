/*
BOJ 14476번: 최대공약수 하나 빼기
DATE: 2022-01-24
Prefix Sum
*/
#include <iostream>
#define MAX 1000001
using namespace std;

long long arr[MAX], leftArr[MAX], rightArr[MAX];

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num;
    int max = -1, idx;
    cin >> n;

    for(int i = 1 ; i <= n ; i++) cin >> arr[i];
    for(int i = 1 ; i <= n ; i++) leftArr[i] = gcd(arr[i], leftArr[i - 1]); // 왼쪽부터 최대공약수 누적
    for(int i = n ; i >= 1 ; i--) rightArr[i] = gcd(arr[i], rightArr[i + 1]); // 오른쪽부터 최대공약수 누적

    for(int i = 1 ; i <= n ; i++){
        num = gcd(leftArr[i - 1], rightArr[i + 1]);

        if(num > max && arr[i] % num != 0) {
            max = num;
            idx = i;
        }
    }

    if(max == -1) cout << -1;
    else cout << max << " " << arr[idx];

    return 0;
}