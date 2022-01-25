/*
BOJ 1484번: 다이어트
2021-12-28
Two pointer
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int g;
    cin >> g;

    int arr[g];
    int start = 0, end = 0;
    vector<int> ans;

    for(int i = 0 ; i < g ; i++) arr[i] = i + 1;

    while(end < g) {
        int weight = arr[end] * arr[end] - arr[start] * arr[start];

        if(weight == g) ans.push_back(arr[end]);

        if(weight < g) end++;
        else start++;
    }

    if(ans.empty()) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << '\n';
    }

    return 0;
}