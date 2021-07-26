//BOJ 2828번: 사과 담기 게임
//2021-03-26
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, dst=0, now = 1;
    cin >> n >> m >> a;

    for(int i = 0 ; i < a ; i++){
        int num;
        cin >> num;

        if(num > (now + m -1)){
            dst += num - (now + m -1);
            now = num - m + 1;
        }
        else if(num < now){
            dst += now - num;
            now = num;
        }
    }

    cout << dst;

    return 0;
}