/*
BOJ 1365번: 꼬인 전깃줄
2022-01-08
Longest Increasing Subsequence
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int n, num, cnt = 0;
    cin >> n;

    vector<int> vec;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;

        if(vec.empty()) vec.push_back(num);
        else {
            int back = vec.back();
            int idx = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
            
            if(num > back) vec.push_back(num);
            else vec[idx] = num;
        }
    }

    cout << n - vec.size();

    return 0;
}