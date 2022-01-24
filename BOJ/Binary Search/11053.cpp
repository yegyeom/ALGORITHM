/*
BOJ 11053번: 가장 긴 증가하는 부분 수열
date: 2021-05-28
update: 2022-01-06 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int n, num;
    cin >> n;

    vector<int> vec;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;

        if(vec.empty()) {
            vec.push_back(num);
            continue;
        }
        
        int back = vec.back();

        if(num > back) {
            vec.push_back(num);
            continue;
        }

        int idx = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
        vec[idx] = num;
    }

    cout << vec.size();

    return 0;
}