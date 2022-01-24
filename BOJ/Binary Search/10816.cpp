/*
BOJ 10816번: 숫자 카드 2 
2021-12-19
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v, ans;
    int n, m, num;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());

    cin >> m;

    for(int i = 0 ; i < m ; i++) {
        cin >> num;
        auto upper = upper_bound(v.begin(), v.end(), num); // 처음으로 value값을 초과하는 원소의 주소
        auto lower = lower_bound(v.begin(), v.end(), num); // value값 보다 크거나 같은 첫번째 원소의 주소

        cout << upper - lower << " ";
    }

    return 0;
}