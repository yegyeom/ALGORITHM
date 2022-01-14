/*
BOJ 14235번: 크리스마스 선물
2022-01-14
*/
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<int> pq;
    int n, a, num;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> a;

        if(a > 0){
            for(int j = 0 ; j < a ; j++){
                cin >> num;
                pq.push(num);
            }
        }
        else{
            if(pq.empty()) cout << -1 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}