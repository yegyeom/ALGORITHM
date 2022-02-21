/*
BOJ 2352번: 반도체 설계
DATE: 2022-02-21
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v;
    int n, num;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> num;

        if(v.empty() || num > v.back()) v.push_back(num);
        else{
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
        }
    }

    cout << v.size();
    
    return 0;
}