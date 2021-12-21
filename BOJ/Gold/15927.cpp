/* 
BOJ 15927번: 회문은 회문아니야!!
2021-12-21
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str, front, back;
    bool flag = true;
    cin >> str;

    int length = str.length();
    
    front = str.substr(0, length / 2);

    if(length % 2 == 0) back = str.substr(length / 2);
    else back = str.substr(length / 2 + 1);

    reverse(back.begin(), back.end());

    if(front == back) { // 팰린드롬 O
        for(int i = 1 ; i < length ; i++) {
            if(str[i - 1] != str[i]) {
                cout << length - 1;
                flag = false;
                break;
            }
        }
        if(flag) cout << -1;
    }
    else cout << str.length(); // 팰린드롬 X
    
    return 0;
}