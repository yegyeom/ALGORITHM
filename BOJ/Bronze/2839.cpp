//BOJ 2839번: 설탕 배달
//2021-04-12
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans=-1;
    cin >> n;

    int m = n/5;

    while(1){
        if(m < 0){
            cout << ans;
            return 0;
        }
        if((n - m*5) % 3 == 0){
            ans = m + (n-m*5)/3;
            break;
        }        
        m--;
    }

    cout << ans;

    return 0;
}