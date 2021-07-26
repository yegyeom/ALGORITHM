//BOJ 14681번: 사분면 고르기
//2021-03-23
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y;
	cin >> x >> y;

	if (x > 0 && y > 0)
		cout << 1;
	else if (x < 0 && y > 0)
		cout << 2;
	else if (x < 0 && y < 0)
		cout << 3;
	else if (x > 0 && y < 0)
		cout << 4;
	
	return 0;
}