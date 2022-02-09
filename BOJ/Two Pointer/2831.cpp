/*
BOJ 2831번: 댄스 파티
DATE: 2022-02-10
Two pointer
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> posM, negM, posW, negW;
    int n, height;
    int a, b, ans = 0;
    cin >> n;

    for(int i = 0 ; i < n * 2 ; i++) {
        cin >> height;

        if(height < 0 && i < n) negM.push_back(abs(height));
        else if(height > 0 && i < n) posM.push_back(height);
        else if(height < 0 && i >= n) negW.push_back(abs(height));
        else if(height > 0 && i >= n) posW.push_back(height);
    }

    sort(negM.begin(), negM.end());
    sort(posM.begin(), posM.end());
    sort(negW.begin(), negW.end());
    sort(posW.begin(), posW.end());

    // 남자 양수 - 여자 음수
    a = 0; b = 0;
    while(a < posM.size() && b < negW.size()) {
        if(posM[a] < negW[b]) {
            ans++;
            a++; b++;
        }
        else b++;
    }

    // 남자 음수 - 여자 양수
    a = 0; b = 0;
    while(a < negM.size() && b < posW.size()) {
        if(negM[a] > posW[b]) {
            ans++;
            a++; b++;
        }
        else a++;
    }

    cout << ans;

    return 0;
}