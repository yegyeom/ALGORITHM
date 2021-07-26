#include <iostream>
#include <stdlib.h>
#include <queue>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		int abs_x = abs(x);

		if (x != 0) {
			pq.push(make_pair(abs_x, x));
		}
		else if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << pq.top().second << "\n";
			pq.pop();
		}
	}
}