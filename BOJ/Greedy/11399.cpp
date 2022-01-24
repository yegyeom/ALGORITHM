/*
BOJ 11399번: ATM
2021-03-29
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, time=0;
    cin >> n;

    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n); 

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            time += arr[j];
        }
    }

    cout << time;

    return 0;
}