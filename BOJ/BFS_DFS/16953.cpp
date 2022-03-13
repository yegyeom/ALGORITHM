/*
BOJ 16953번: A → B
DATE: 2022-03-13
-
x * 2 연산과 y * 10 + 1 연산 중 중복이 발생할 수 없으므로 방문 체크 안 해줘도 됨
*/
#include <iostream>
#include <queue>
#define ll long long
using namespace std;

ll a, b;
int cnt;

void bfs(ll a){
    queue<pair<ll,ll>> q;
    q.push({a, 1});

    while(!q.empty()){
        pair<ll,ll> cur = q.front();
        q.pop();

        if(cur.first == b) {
            cout << cur.second;
            return;
        }

        if(cur.first * 2 <= b) q.push({cur.first * 2, cur.second + 1});
        if(cur.first * 10 + 1 <= b) q.push({cur.first * 10 + 1, cur.second + 1});
    }

    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;

    bfs(a);

    return 0;
}