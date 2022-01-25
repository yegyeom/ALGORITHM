/*
BOJ 11723번: 집합
DATE: 2022-01-25
Bitmask
*/
#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, num;
    string cmd;

    int s = 0;

    cin >> m;

    for(int i = 0 ; i < m ; i++){
        cin >> cmd;

        if(cmd == "add") {
            cin >> num;
            s |= (1 << num);
        }
        else if(cmd == "remove") {
            cin >> num;
            s &= ~(1 << num);
        }
        else if(cmd == "check") {
            cin >> num;
            if(s & (1 << num)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(cmd == "toggle") {
            cin >> num;
            if(s & (1 << num)) s &= ~(1 << num);
            else s |= (1 << num);
        }
        else if(cmd == "all") {
            s = (1 << 21) - 1;
        }
        else if(cmd == "empty") s = 0;
    }

    return 0;
}