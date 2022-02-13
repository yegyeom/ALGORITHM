/*
BOJ 2441번: 별 찍기 - 4
DATE: 2022-02-13
*/
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = n ; i > 0 ; i--){
        for(int j = 0 ; j < n - i ; j++) cout << " ";
        for(int j = 0 ; j < i ; j++) cout << "*";
        cout << '\n';
    }

    return 0;
}