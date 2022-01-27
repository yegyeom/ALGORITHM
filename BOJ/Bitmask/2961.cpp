/*
BOJ 2961번: 도영이가 만든 맛있는 음식
DATE: 2022-01-26
Bitmask
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b;
    long long minimum = 10000000000;
    cin >> n;

    vector<pair<int,int>> vec(n);

    for(int i = 0 ; i < n ; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    for(int i = 1 ; i < (1 << n) ; i++) { // 부분 집합 전체 개수
        long long a = 1, b = 0;

        for(int j = 0 ; j < n ; j++){
            if(i & (1 << j)) {
                a *= vec[j].first; 
                b += vec[j].second;
            }
        }

        minimum = min(minimum, abs(a - b));
    }

    cout << minimum;
    
    return 0;
}