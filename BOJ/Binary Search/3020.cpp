/*
BOJ 3020번: 개똥벌레
DATE: 2022-01-03
UPDATE: 2022-01-17
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> down, up;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, h, a, b;
    int min = 500000, cnt = 0;
    cin >> n >> h;

    for(int i = 0 ; i < n / 2; i++) {
        cin >> a >> b;
        down.push_back(a); up.push_back(b);
    }

    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    vector<int> ans(h);
   
    for(int i = 1 ; i <= h ; i++) {
        int downIdx = lower_bound(down.begin(), down.end(), i) - down.begin(); // 석순
        int upIdx = lower_bound(up.begin(), up.end(), h - i + 1) - up.begin(); // 종유석
        int cur = n - (downIdx + upIdx); // 높이 i일 때 몇 개의 장애물을 파괴하는지
        
        if(cur < min) {
            min = cur;
            cnt = 1;
        }
        else if(cur == min) cnt++;
    }

    cout << min << " " << cnt;

    return 0;
}