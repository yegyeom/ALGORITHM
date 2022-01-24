/*
BOJ 2343번: 기타 레슨
2021-12-19
Binary Search
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, num, ans = 1000000000;
    int start, end, mid, sum, cnt;
    
    cin >> n >> m;

    int arr[n];

    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    start = 1;
    end = sum;

    while(start <= end) {
        cnt = 1;
        sum = 0;
        mid = (start + end) / 2;

        for(int i = 0 ; i < n ; i++) {
            if(arr[i] > mid) { // 모든 강의가 들어가야 함
                cnt = n + 1; // M <= N (cnt는 무조건 M보다 크게 됨)
                break;
            }

            sum += arr[i];

            if(sum > mid){
                cnt++;
                sum = arr[i];
            }
        }

        if(cnt <= m) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << ans;

    return 0;
}