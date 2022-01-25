/*
BOJ 11728번: 배열 합치기
2021-12-28
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v;
    int a, b, n;
    cin >> a >> b;

    for(int i = 0 ; i < a ; i++) {
        cin >> n;
        v.push_back(n);
    }

    for(int i = 0 ; i < b ; i++) {
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    for(int i = 0 ; i < v.size() ; i++) cout << v[i] << " ";

    return 0;
}