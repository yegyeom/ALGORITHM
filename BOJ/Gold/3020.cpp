/*
BOJ 3020번: 개똥벌레
2021-01-03
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, h, num;
    cin >> n >> h;

    int arr1[n/2], arr2[n/2];

    for(int i = 0 ; i < n / 2; i++) cin >> arr1[i] >> arr2[i];
    sort(arr1, arr1 + n / 2);
    sort(arr2, arr2 + n / 2);

    vector<int> ans(h);

    for(int i = 1 ; i <= h ; i++) {
        // 높이 i일 때 몇 개의 장애물을 파괴하는지
        auto upper = upper_bound(arr1, arr1 + n / 2, h);
        auto lower = lower_bound(arr1, arr1 + n / 2, i);
        ans[i - 1] += upper - lower;

        upper = upper_bound(arr2, arr2 + n / 2, h);
        lower = lower_bound(arr2, arr2 + n / 2, i);
        ans[h - i] += upper - lower; 
    }

    sort(ans.begin(), ans.end());
    auto upper = upper_bound(ans.begin(), ans.end(), ans[0]);
    auto lower = lower_bound(ans.begin(), ans.end(), ans[0]);

    cout << ans[0] << " " << upper - lower;
    return 0;
}