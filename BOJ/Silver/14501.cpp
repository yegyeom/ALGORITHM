//BOJ 14501번: 퇴사
//2021-10-07
//Dynamic Programming
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, max_val;
    cin >> n;

    int arr[2][n];

    for(int i = 0 ; i < n ; i++) {
        vector<int> tmp;
        int t, p; //기간, 금액
        
        cin >> t >> p;
        arr[1][i] = t;

        if(i + t > n) {
            arr[0][i] = 0;
            continue;
        }

        for(int j = 0 ; j < i ; j++) {
            if(j + arr[1][j] <= i) tmp.push_back(arr[0][j]);
        }

        if(tmp.size() > 0) max_val = *max_element(tmp.begin(), tmp.end());
        arr[0][i] = max_val + p;
    }

    cout << *max_element(arr[0], arr[0] + n);

    return 0;
}