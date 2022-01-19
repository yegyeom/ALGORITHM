/*
BOJ 3078번: 좋은 친구
DATE: 2022-01-19
Sliding Window
*/
#include <iostream>
#include <vector>
#include <map>
#define startNameLen vec[s].second
#define endNameLen vec[e].second
using namespace std;

vector<pair<int,int>> vec;
map<int, int> m; 
int n, k;
int s = 0, e = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    long long ans = 0;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> str;
        vec.push_back({i + 1, str.length()}); // (등수, 이름의 길이)
    }
    
    while(1){
        if(e == n) { // end는 끝에 다다르고 start만 증가해야 하는 경우
            while(s < n){
                // 범위를 벗어난 값 제거 (창문에서 나가는 값)
                if(m[startNameLen] > 1) m[startNameLen]--;
                else if(m[startNameLen] == 1) m.erase(m[startNameLen]);
                s++;

                if(m[startNameLen] > 1) ans += m[startNameLen] - 1; // 쌍의 개수 구하기
            }
            break;
        }

        if(e - s > k) { // 범위를 벗어난 값 제거 (창문에서 나가는 값)
            if(m[startNameLen] > 1) m[startNameLen]--;
            else if(m[startNameLen] == 1) m.erase(startNameLen);
            s++;
        }

        while(e - s <= k){ // end 값을 증가시키며 새로운 값 처리 (창문에 새로 들어오는 값)
            if(m.find(endNameLen) == m.end()) m.insert({endNameLen, 1});
            else m[endNameLen]++;

            if(e - s == k){ // 쌍의 개수 구하기
                if(m[startNameLen] > 1) ans += m[startNameLen] - 1;
            }

            e++;
        }
    }

    cout << ans;

    return 0;
}