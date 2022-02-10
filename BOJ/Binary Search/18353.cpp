/*
BOJ 18353번: 병사 배치하기
DATE: 2022-01-08
UPDATE: 2022-02-11
Longest Increasing Subsequence
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num;
    cin >> n;
    
    vector<int> v1(n), v2;

    for(int i = 0 ; i < n ; i++) cin >> v1[i];
    reverse(v1.begin(), v1.end());

    for(int i = 0 ; i < n ; i++) {
        if(v2.empty() || v1[i] > v2.back()) {
            v2.push_back(v1[i]);
            continue;
        }

        int idx = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
        v2[idx] = v1[i];
    }

    cout << n - v2.size();

    return 0;
}