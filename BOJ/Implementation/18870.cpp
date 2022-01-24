/*
BOJ 18870번: 좌표 압축
DATE: 2022-01-13
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> input, vec;
    int n, num;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> num;
        input.push_back(num);
    }

    vec = input;
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for(int i = 0 ; i < n ; i++){
        int idx = lower_bound(vec.begin(), vec.end(), input[i]) - vec.begin();
        cout << idx << " ";
    }

    return 0;
}