/*
BOJ 1715번: 카드 정렬하기
DATE: 2022-01-30
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, num, ans = 0;
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        pq.push(num);
    }

    while(pq.size() > 1) {
        int sum = 0;

        for(int i = 0 ; i < 2 ; i++) {
            sum += pq.top();
            pq.pop();
        }

        ans += sum;
        pq.push(sum);
    }

    cout << ans;

    return 0;
}