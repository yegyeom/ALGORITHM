/*
BOJ 14002번: 가장 긴 증가하는 부분 수열 4
2022-01-06
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input, lis, index;

void backtrace(int idx, int num){
    if(idx == 0) return;
    if(index[idx - 1] == num){
        backtrace(idx - 1, num - 1);
        cout << input[idx - 1] << " ";
    }
    else backtrace(idx - 1, num);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        input.push_back(num);

        int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();

        if(lis.empty()) lis.push_back(num);
        else{
            int back = lis.back();

            if(back < num) lis.push_back(num);
            else lis[idx] = num;
        }

        index.push_back(idx); //i번째 원소가 lis 내에서 위치하는 인덱스를 저장
    }
    
    cout << lis.size() << '\n';
    backtrace(n, lis.size() - 1); 

    return 0;
}