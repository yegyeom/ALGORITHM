/*
BOJ 1300번: K번째 수
DATE: 2022-02-09
Binary Search
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, k;
    long long left, right, mid, ans;

    cin >> n >> k;

    left = 0; right = n * n;

    while(left <= right) {
        long long cnt = 0;
        mid = (left + right) / 2; // K번째 수를 mid라고 설정

        for(int i = 1 ; i <= n ; i++) cnt += min(mid / i, n); // mid보다 작거나 같은 숫자의 개수

        if(cnt < k) left = mid + 1;
        else {
            right = mid - 1;
            ans = mid;    
        }
    }

    cout << ans;

    return 0;
}