/*
BOJ 2230번: 수 고르기
DATE: 2022-02-08
Two pointer
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    int start, end, minVal = 2e9;
    cin >> n >> m;

    int arr[n];

    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    sort(arr, arr + n);

    start = 0; end = 0;

    while(end < n) {
        int diff = arr[end] - arr[start];

        if(diff == m) {
            minVal = m;
            break;
        }

        if(diff < m) end++;
        else {
            minVal = min(minVal, diff);
            start++;
        }
    }

    cout << minVal;

    return 0;
}