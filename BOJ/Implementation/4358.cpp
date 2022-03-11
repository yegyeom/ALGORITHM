/*
BOJ 4358번: 생태학
DATE: 2022-03-11
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    int total = 0;

    while(getline(cin, str)){
        m[str]++;
        total++;
    }

    cout << fixed;
    cout.precision(4);
    for(auto i : m) cout << i.first << " " << (double)i.second / total * 100 << '\n';

    return 0;
}