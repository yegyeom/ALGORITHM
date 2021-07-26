//BOJ 11650번: 좌표 정렬하기
//2021-05-04
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<pair<int, int>> v;
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int x, y;
        cin >> x >> y;

        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < n ; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
}