//BOJ 12904번: A와 B
//2021-11-22
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t, tmp;
    cin >> s >> t;

    while(t.length() > s.length()){
        char last = t[t.length() - 1]; //t의 마지막 글자 
        t.erase(t.length() - 1, 1); //t의 마지막 글자 제거
        
        if(last == 'B'){
            reverse(t.begin(), t.end());
        }

        if(t == s) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
    return 0;
}