//BOJ 1110번: 더하기 사이클
//2021-03-23
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, units, tens, num, cycle=0;
	cin >> n;

	num = n;
    
	while (1) {
		cycle++;

		if (num < 10) {
			num = 10 * num + num;
		}
		else if (num >=10) {
			units = num % 10;
			tens = num / 10;
			num = 10 * units + (units+tens)%10;
		}

		if (num == n) {
			cout << cycle << "\n";
			break;
		}
	}

	return 0;
}