/*
BOJ 14002번: 가장 긴 증가하는 부분 수열 5
DATE: 2022-02-21
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input, lis, index;

void backtrace(int idx, int num){
    if(idx == -1) return;
    if(index[idx] == num){
        backtrace(idx - 1, num - 1);
        cout << input[idx] << " ";
    }
    else backtrace(idx - 1, num);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;

        int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();

        if(lis.empty() || num > lis.back()) lis.push_back(num);
        else lis[idx] = num;

        input.push_back(num);
        index.push_back(idx); //i번째 원소가 lis 내에서 위치하는 인덱스를 저장
    }
    
    cout << lis.size() << '\n';
    backtrace(n - 1, lis.size() - 1); 

    return 0;
}