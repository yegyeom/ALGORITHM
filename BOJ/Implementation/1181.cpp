/*
BOJ 1181번: 단어 정렬
DATE: 2021-04-29
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, string>> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        v.push_back(make_pair(str.length(), str));
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); 

    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i].second << '\n';
    }

    return 0;
}