//BOJ 1149번: RGB거리
//2021-07-27
#include <iostream>
#include <algorithm>
using namespace std;

int house[1000][3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r, g, b;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> r >> g >> b;
        house[i][0] = min(house[i-1][1], house[i-1][2]) + r;
        house[i][1] = min(house[i-1][0], house[i-1][2]) + g;
        house[i][2] = min(house[i-1][0], house[i-1][1]) + b;
    }

    cout << *min_element(house[n-1], house[n-1] + 3);

    return 0;
}