/*
BOJ 17609번: 회문
DATE: 2022-03-18
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    string orgStr, revStr;

    cin >> t;

    while(t--){
        cin >> revStr;

        orgStr = revStr;
        reverse(revStr.begin(), revStr.end());

        if(orgStr == revStr) cout << 0 << '\n';
        else{
            int s = 0, e = orgStr.length() - 1;
            int cnt = 0;

            while(s < e){
                if(orgStr[s] == orgStr[e]){
                    s++;
                    e--;
                }
                else if(orgStr[s + 1] == orgStr[e] && orgStr[s] != orgStr[e - 1] && cnt == 0){
                    cnt++;
                    s++;
                }
                else if(orgStr[s] == orgStr[e - 1] && orgStr[s + 1] != orgStr[e] && cnt == 0){
                    cnt++;
                    e--;
                }
                else{
                    string A = orgStr, B = orgStr;
                    A.erase(s, 1);
                    B.erase(e, 1);
                    
                    string revA = A, revB = B;
                    reverse(revA.begin(), revA.end());
                    reverse(revB.begin(), revB.end());

                    if(revA == A || revB == B) cout << 1 << '\n';
                    else cout << 2 << '\n';

                    cnt = 100000;
                    break;
                }
            }

            if(cnt == 1) cout << 1 << '\n';
        }
    }

    return 0;
}