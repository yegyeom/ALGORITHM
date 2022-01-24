/*
BOJ 14921번: 용액 합성하기
DATE: 2022-01-17
Two pointer
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v, ans(2);
    int n, num;
    int start, end, min;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> num;
        v.push_back(num);
    }

    start = 0; end = n - 1;
    min = 100000001;

    while(start < end){
        int sum = v[start] + v[end];

        if(abs(sum) < min){
            ans[0] = v[start];
            ans[1] = v[end];
            min = abs(sum);
        }

        if(sum < 0) start++;
        else end--;
    }

    cout << ans[0] + ans[1];

    return 0;
}