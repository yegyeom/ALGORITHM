/*
BOJ 2503번: 카드
DATE: 2022-03-11
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

map<ll, ll> m;

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a;
        m[a]++;
    }

    vector<pair<ll,ll>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    cout << v[0].first;

    return 0;
}