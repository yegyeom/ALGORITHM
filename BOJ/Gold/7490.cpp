/*
BOJ 7490번: 0 만들기
2021-12-20
Brute force ver.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
int input, n, r;
int dpArr[8] = {0,};

void duplicatePermutation(int depth) {
    if(depth == r) { // 0: 더하기 1: 빼기 2: 붙이기
        int sum = 0, cnt = 0;
        string calc = "1", origin = "1", tmp;

        for(int i = 1 ; i <= r ; i++) {
            if(dpArr[i - 1] == 0) {
                tmp = "+" + to_string(i + 1);
                calc += tmp; origin += tmp;
            }
            else if(dpArr[i - 1] == 1) {
                tmp = "-" + to_string(i + 1);
                calc += tmp; origin += tmp;
            }
            else {
                calc += to_string(i + 1);
                origin += " " + to_string(i + 1);
            }
        }

        for(int i = 0 ; i < calc.length() ; i++) {
            tmp.clear();
            cnt = 0;

            if(isdigit(calc[i])) {
                while(isdigit(calc[i])){
                    tmp += calc[i++];
                    cnt++;
                }
                
                i--;

                if(cnt == 1) {
                    if(calc[i - cnt] == '+') sum += calc[i] - '0';
                    else if(calc[i - cnt] == '-') sum -= calc[i] - '0';
                    else sum = calc[i] - '0';
                }
                else if(cnt > 1) {
                    if(calc[i - cnt] == '+') sum += stoi(tmp);
                    else if(calc[i - cnt] == '-') sum -= stoi(tmp);
                    else sum = stoi(tmp);
                }
            }
        }

        if(sum == 0) ans.push_back(origin);
        return;
    }

    for(int i = 1 ; i <= n ; i++) {
        dpArr[depth] = i - 1;
        duplicatePermutation(depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int tc, input;
    cin >> tc;

    for(int i = 0 ; i < tc ; i++) {
        ans.clear();
        for(int j = 0 ; j < r ; j++) dpArr[j] = 0;

        cin >> input; // 1부터 n까지의 정수들

        n = 3; // + - 공백
        r = input - 1; // 연산자 개수

        duplicatePermutation(0); // 중복 순열

        sort(ans.begin(), ans.end()); // ASCII 순서에 따라 출력
        for(int j = 0 ; j < ans.size() ; j++) cout << ans[j] << "\n";
        cout << '\n';
    }

    return 0;
}