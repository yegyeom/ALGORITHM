/*
BOJ 13398번: 연속합 2
DATE: 2021-07-20 
*/
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[MAX], left[MAX], right[MAX];
    int n, ans;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    ans = left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    for(int i = 1 ; i < n ; i++){
        left[i] = max(arr[i], arr[i] + left[i-1]);
        ans = max(ans, left[i]);
    }

    for(int i = n - 2 ; i >= 0 ; i--){
        right[i] = max(arr[i], arr[i] + right[i + 1]);
    }

    for(int del = 1 ; del < n - 1 ; del++){
        ans = max(ans, left[del - 1] + right[del + 1]); 
    }

    cout << ans;

    return 0;
}