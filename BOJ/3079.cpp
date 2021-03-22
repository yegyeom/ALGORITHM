#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000000000000000

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m, total, start, end, mid;
    long long min = MAX;
    cin >> n >> m;

    int time[n];
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    sort(time, time + n);
    end = m * time[n - 1];

    while (end - start >= 0) {
        mid = (start + end) / 2;
        total = 0;
        for (int i = 0; i < n; i++) {
            total += mid / time[i];
        }

        if (total >= m) {
            end = mid - 1;
            if (mid < min) min = mid;
        }
        else if (total < m) {
            start = mid + 1;
        }
    }

    cout << min;

    return 0;
}