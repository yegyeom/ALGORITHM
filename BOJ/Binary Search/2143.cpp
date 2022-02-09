/*
BOJ 2143번: 두 배열의 합
DATE: 2022-02-09
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int t, n, m, num;
    long long sum, ans = 0;

    vector<long long> a, b, aSum, bSum;

    cin >> t >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        a.push_back(num);
    }

    cin >> m;
    for(int i = 0 ; i < m ; i++) {
        cin >> num;
        b.push_back(num);
    }
    
    for(int i = 0 ; i < n ; i++){
        aSum.push_back(a[i]);
        sum = a[i];

        for(int j = i + 1 ; j < n ; j++){
            sum += a[j];
            aSum.push_back(sum);
        }
    }

    for(int i = 0 ; i < m ; i++){
        bSum.push_back(b[i]);
        sum = b[i];

        for(int j = i + 1 ; j < m ; j++){
            sum += b[j];
            bSum.push_back(sum);
        }
    }

    sort(bSum.begin(), bSum.end());

    for(int i = 0 ; i < aSum.size() ; i++) {
        int diff = t - aSum[i]; 

        auto lower = lower_bound(bSum.begin(), bSum.end(), diff);
        auto upper = upper_bound(bSum.begin(), bSum.end(), diff);

        ans += upper - lower; //bSum에 존재하는 diff의 개수
    }

    cout << ans;

    return 0;
}