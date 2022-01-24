/*
BOJ 9613번: GCD 합
DATE: 2022-01-24
Euclidean algorithm
*/
#include <iostream>
using namespace std;

long long gcd(int a, int b){
    return b ? gcd(b, a % b): a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc, n;
    cin >> tc;

    for(int i = 0 ; i < tc ; i++){
        cin >> n;
        long long arr[n], sum = 0;

        for(int j = 0 ; j < n ; j++) cin >> arr[j];

        for(int j = 0 ; j < n ; j++){
            for(int k = j + 1 ; k < n ; k++){
                if(arr[j] > arr[k]) sum += gcd(arr[j], arr[k]);
                else sum += gcd(arr[k], arr[j]);
            }
        }

        cout << sum << '\n';
    }

    return 0;
}