/*
BOJ 2075번: N번째 큰 수
DATE: 2022-01-30
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, num;
    cin >> n;

    for(int i = 0 ; i < n * n ; i++) {
        cin >> num;
        pq.push(num);

        if(pq.size() > n) pq.pop();
    }

    cout << pq.top();

    return 0;
}