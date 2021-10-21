//BOJ 20055번: 컨베이어 벨트 위의 로봇
//2021-10-21
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, in, out;
    int ans = 0;
    cin >> n >> k;

    in = 0; out = n - 1; // 올리는 위치, 내리는 위치
    vector<pair<int,int>> v(n + n); // 내구도, 로봇 존재 여부
    
    for(int i = 0 ; i < n + n ; i++) {
        cin >> v[i].first;
        v[i].second = 0;
    }

    while(1) {
        bool flag = true;
        int check = 0;
        ans++; // 단계

        // 한 칸씩 회전
        pair<int,int> tmp = v[n + n - 1];

        for(int i = n + n - 2 ; i >= 0 ; i--) v[i + 1] = v[i];
        v[0] = tmp;

        if(v[out].second) v[out].second = 0;

        // 로봇 이동
        for(int i = n - 2 ; i >= 0 ; i--) {
            if(!v[i + 1].second && v[i].second && v[i + 1].first > 0) {
                v[i].second = 0;
                v[i + 1].first -= 1;
                v[i + 1].second = 1;

                if(i + 1 == out) {
                    v[i + 1].second = 0;
                }
            }
        }

        // 로봇 올리기
        if(v[in].first > 0) {
            v[in].first -= 1;
            v[in].second = 1;
        }

        // 내구도 확인
        for(int i = 0 ; i < n + n ; i++) {
            if(v[i].first == 0) {
                check++;
                if(check == k) {
                    flag = false;
                    break;
                }
            }
        }

        if(!flag) break;
    }

    cout << ans;

    return 0;
}