//BOJ 2960번: 에라토스테네스의 체
//2021-10-10
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[1001] = {0, };
    int n, k, cnt = 0;
    cin >> n >> k;

    for(int i = 2 ; i <= n ; i++) {
        for(int j = i ; j <= n ; j += i) {
            if(arr[j] == 0) {
                cnt++;
                arr[j] = j;
            }
            if(cnt == k) {
                cout << j;
                break;
            }
        }
        if(cnt == k) break;
    }

    return 0;
}