/*
BOJ 10211번: Maximum Subarray
DATE: 2022-01-23
Prefix Sum
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc, n;
    
    cin >> tc;

    for(int i = 0 ; i < tc ; i++){
        cin >> n;

        int arr[n];
        int maxVal = -1e9;
        int sum = 0;

        for(int j = 0 ; j < n ; j++) {
            cin >> arr[j];
            sum = max(0, sum) + arr[j];
            maxVal = max(maxVal, sum);
        }

        cout << maxVal << '\n';
    }

    return 0;
}