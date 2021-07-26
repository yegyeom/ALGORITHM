#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	priority_queue<int, vector <int>, greater <int>>pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != 0) {
			pq.push(x);
		}
		else if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
	return 0;
}