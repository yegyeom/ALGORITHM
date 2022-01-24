//BOJ 10817번: 세 수
//2021-05-04
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    vector<int> v;

    for(int i = 0 ; i < 3 ; i++){
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    cout << v[1];

    return 0;
}