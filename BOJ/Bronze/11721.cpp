//BOJ 11721번: 열 개씩 끊어 출력하기
//2021-05-04
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;

    while(1){
        if(str.length() == 0)
            break;
        
        cout << str.substr(0, 10) << '\n';
        str.erase(0, 10);
    }

    return 0;
}