/*
BOJ 14425번: 문자열 집합
DATE: 2021-02-15
*/
#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, cnt=0;
    cin >> n >> m;

    map<string, int> m1;

    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;

        m1[str] = 1;
    }

    for(int i = 0 ; i < m ; i++){
        string str;
        cin >> str;
        
        if(m1[str] == 1) cnt++;
    }

    cout << cnt;

    return 0;
}