/*
BOJ 12015번: 가장 긴 증가하는 부분 수열 2
DATE: 2022-02-21
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

        if(vec.empty() || num > vec.back()) vec.push_back(num);
        else{
            int idx = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
            vec[idx] = num;
        }
    }

    cout << vec.size();

    return 0;
}