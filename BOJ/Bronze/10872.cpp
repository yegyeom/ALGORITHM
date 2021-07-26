//BOJ 10872번: 팩토리얼
//2021-02-15
#include <iostream>
using namespace std;
int ans = 1;

void fac(int num){
    if(num >= 1){
        ans *= num;
        fac(num - 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    fac(n);

    cout << ans; 
    return 0;
}