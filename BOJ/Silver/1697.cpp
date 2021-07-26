#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int sec[MAX] = { 0, };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k, ans;
    int move[] = { -1, 1, 2 };
    queue <int> q;

    cin >> n >> k;

    sec[n] = 1;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == k) {
            cout << sec[cur] - 1;
            break;
        }

        int next;
        for (int i = 0; i < 3; i++) {
            if (i == 0 || i == 1)
                next = cur + move[i];
            else
                next = cur * move[i];

            if (next >= 0 && next <= 100000 && !sec[next]) {
                q.push(next);
                sec[next] = sec[cur] + 1;
            }
        }
    }

    return 0;
}