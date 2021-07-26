//BOJ 1912번: 연속합
//2021-07-20
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long input[100001];
    long long n, ans;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> input[i];
    }

    ans = input[0];

    for(int i = 1 ; i < n ; i++){
        input[i] = max(input[i], input[i] + input[i-1]);
        ans = max(ans, input[i]);
    }

    cout << ans;

    return 0;
}