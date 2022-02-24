/*
BOJ 2568번: 전깃줄 - 2
DATE: 2022-02-24
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inputA, inputB, lis, index;

void backtrace(int i, int num){
    if(i == -1) return;
    if(index[i] == num){
        inputA[i] = -1; // 가장 긴 증가하는 부분 수열에 해당하는 인덱스는 -1로 처리
        backtrace(i - 1, num - 1);
    }
    else backtrace(i - 1, num);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<pair<int,int>> p;
    int n, a, b;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        p.push_back({a, b});
    }

    sort(p.begin(), p.end());
    
    for(int i = 0 ; i < n ; i++){
        inputA.push_back(p[i].first); // A 전봇대
        inputB.push_back(p[i].second); // B 전봇대

        int num = p[i].second;
        int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();

        if(lis.empty() || num > lis.back()) lis.push_back(num);
        else lis[idx] = num;

        index.push_back(idx);
    }
    
    cout << n - lis.size() << '\n';

    backtrace(n - 1, lis.size() - 1); 

    for(int i = 0 ; i < n ; i++){
        if(inputA[i] != -1) cout << inputA[i] << '\n';
    }

    return 0;
}