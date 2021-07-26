//BOJ 15552번: 빠른 A+B
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, a, b;
	cin >> t;

	for (int i = 0; i < t ; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}