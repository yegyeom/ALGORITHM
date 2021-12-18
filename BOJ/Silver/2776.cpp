/*
BOJ 2776번: 암기왕
2021-12-19
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    vector<int> v;
    int tc, n, m, num;
    cin >> tc;

    for(int i = 0 ; i < tc ; i++) {
        v.clear(); 
        cin >> n;
        
        for(int i = 0 ; i < n ; i++) {
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end());

        cin >> m;

        for(int i = 0 ; i < m ; i++) {
            cin >> num;
            
            auto upper = upper_bound(v.begin(), v.end(), num);
            auto lower = lower_bound(v.begin(), v.end(), num);

            if(upper - lower > 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}