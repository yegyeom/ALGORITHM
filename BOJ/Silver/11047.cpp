#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, val, cnt=0;
	int arr[10];

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> val;
		arr[i] = val;
	}

	for (int i = n-1 ; i >= 0; i--) {
		if (k / arr[i] > 0) { //���� ����̸�
			cnt += k / arr[i]; //���� ���� ����
			k -= arr[i] * (k / arr[i]); //������ ���� ����ŭ ����
		}
	}

	cout << cnt;

	return 0;
}