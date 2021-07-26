//BOJ 1065번: 한수
//2021-05-18
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans=0;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        if(i < 100){
            ans++;
            continue;
        }
        else{
            int n1 = i % 10; //���� �ڸ�
            int n2 = (i / 10) % 10; //���� �ڸ�
            int n3 = i / 100; //���� �ڸ�

            if(n3 - n2 == n2 - n1){
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}