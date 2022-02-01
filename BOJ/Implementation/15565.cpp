/*
BOJ 15565번: 귀여운 라이언
DATE: 2022-02-01
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    vector<int> vec;
    int n, k, num;
    int ans = 1000001;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        if(num == 1) vec.push_back(i);
    }

    if(vec.size() < k) {
        cout << -1;
        return 0;
    }

    for(int i = 0 ; i <= vec.size() - k ; i++) {
        ans = min(ans, vec[i + k - 1] - vec[i] + 1);
    }

    cout << ans;

    return 0;
}