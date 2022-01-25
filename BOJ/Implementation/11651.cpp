/*
BOJ 11651번: 좌표 정렬하기 2
DATE: 2021-04-29
*/
#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int x, y;
        cin >> x >> y;
        pq.push(make_pair(y, x));
    }

    for(int i = 0 ; i < n ; i++){
        cout << pq.top().second << " " << pq.top().first << '\n';
        pq.pop();
    }

    return 0;
}