/*
BOJ 5635번: 생일
DATE: 2022-05-26
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;  

    vector<pair<pair<int,int>, pair<int, string>>> v(n);

    for(int i = 0 ; i < n ; i++){
        cin >> v[i].second.second >> v[i].second.first >> v[i].first.second >> v[i].first.first;
    }

    sort(v.begin(), v.end());
    cout << v.back().second.second << "\n" << v.front().second.second;

    return 0;
}