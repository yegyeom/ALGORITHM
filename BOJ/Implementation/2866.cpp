/*
BOJ 2866번: 문자열 잘라내기
DATE: 2021-11-16
*/
#include <iostream>
#include <set>
using namespace std;

char arr[1000][1000];
int r, c;

bool check_overlap() { // 마지막 줄만 검사
    int alpha[26] = {0, };
    bool flag = true;

    for(int i = 0 ; i < c ; i++) {
        if(++alpha[arr[r-1][i] - 97] > 1) {
            flag = false;
            break;
        }
    }

    return flag;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cnt = 0;
    cin >> r >> c;

    for(int i = 0 ; i < r ; i++) {
        for(int j = 0 ; j < c ; j++) {
            cin >> arr[i][j];
        }
    }

    if(check_overlap()) cout << r - 1; // 문자열 중복 X
    else { // 문자열 중복 O
        string str[c];
        set<string> s;

        for(int i = r - 1 ; i >= 0 ; i--) {
            for(int j = 0 ; j < c ; j++) {
                str[j] += arr[i][j];
                s.insert(str[j]);
            }

            if(s.size() == c) {
                cout << i;
                break;
            }

            s.clear();
        }
    }

    return 0;
}