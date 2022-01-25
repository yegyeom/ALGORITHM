/*
BOJ 11501��: �ֽ�
DATE: 2021-01-10
*/
#include <iostream>
using namespace std;
int price[1000000] = { 0, };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n, max;
	long long ans;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> price[j];
		}

		ans = 0;
		max = price[n-1]; 

		for (int k = n-1 ; k >= 0 ; k--) {
			if (price[k] > max) { //���� ū �ְ�
				max = price[k];
			}
			else if (price[k] < max) { //���� �߻�
				ans += max - price[k];
			}
		}

		if (max == price[0]) { //�ִ� ���� 0
			cout << 0 << "\n";
			continue;
		}

		cout << ans << "\n";

	}

	return 0;

}
