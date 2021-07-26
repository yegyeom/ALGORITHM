//BOJ 4673?: ?? ??
//2021-03-23
#include <iostream>

using namespace std;

int d(int num) {
	int sum = num;

	while (num != 0) {
		sum += num % 10;
		num = num / 10;
	}

	return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	bool arr[10001] = { false, };

	for (int i = 1; i <= 10000; i++) {
		int idx = d(i);

		if(idx <= 10000)
			arr[idx] = true;
	}

	for (int i = 1; i <= 10000; i++) {
		if (!arr[i])
			cout << i << endl;
	}

	return 0;
}