/*
BOJ 1966번: 프린터 큐
2021-10-14
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc, n, m, num;
    cin >> tc;

    for(int i = 0 ; i < tc ; i++) {
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        int order = 1, idx;

        cin >> n >> m;

        for(int j = 0 ; j < n ; j++) {
            cin >> num;
            q.push(make_pair(num, j)); // 중요도, 순서
            pq.push(num);

            if(j == m) idx = j; // 목표 문서
        }

        int max = pq.top();

        while(!q.empty()) {
            pair<int, int> cur = q.front();

            if(cur.first < max) {
                while(cur.first != max) {
                    q.push(q.front()); q.pop();
                    cur = q.front();
                }
            }
            else  {
                if(cur.second == idx) {
                    cout << order << '\n';
                    break;
                }
                else {
                    q.pop(); pq.pop();
                    max = pq.top();
                    order++;
                }
            }
        }
    }

    return 0;
}