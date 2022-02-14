/*
BOJ 2443번: 별 찍기 - 6
DATE: 2022-02-14
*/
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < i - 1 ; j++) cout << " ";
        for(int j = 0 ; j < 2 * n - 2 * i + 1 ; j++) cout << "*";
        cout << '\n';
    }

    return 0;
}