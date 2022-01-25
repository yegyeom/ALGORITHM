/*
BOJ 15903번: 카드 합체 놀이
DATE: 2021-01-10
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, a;
	long long num1, num2, sum = 0;
	priority_queue<long long, vector <long long>, greater <long long>>pq;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}
	
	for (int j = 0; j < m; j++) {
		//가장 작은 두 값
		num1 = pq.top();
		pq.pop();
		num2 = pq.top();
		pq.pop();

		//더한 값으로 덮어쓰기
		pq.push(num1 + num2);
		pq.push(num1 + num2);
	}

	//모든 카드 값 더하기
	for (int k = 0; k < n; k++) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;

	return 0;
}