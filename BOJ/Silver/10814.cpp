/*
BOJ 10814번: 나이순 정렬
2022-01-15
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b) {
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<pair<int,string>> vec;
    int n, age;
    string name;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> age >> name;
        vec.push_back({age, name});
    }

    stable_sort(vec.begin(), vec.end(), cmp);

    for(int i = 0 ; i < n ; i++) cout << vec[i].first << " " << vec[i].second << '\n';

    return 0;
}