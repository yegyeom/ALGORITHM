/*
BOJ 16401번: 과자 나눠주기
DATE: 2022-06-04
Binary Search
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long m, n, sum = 0;
    long long start, mid, end, cnt;
    long long ans = -1;

    cin >> m >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    start = 0;
    end = sum;

    while(start <= end){
        cnt = 0;
        mid = (start + end) / 2;
        
        for(int i = 0 ; i < n ; i++){
            if(arr[i] >= mid && mid > 0) cnt += arr[i] / mid;
        }

        if(cnt >= m) {
            start = mid + 1;
            ans = max(ans, mid);
        }
        else end = mid - 1;
    }

    cout << (ans == -1 ? 0 : ans);

    return 0;
}