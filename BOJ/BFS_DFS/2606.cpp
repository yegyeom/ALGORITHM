/*
BOJ 2606번: 바이러스
DATE: 2021-01-18
BFS
*/
#include <iostream>
#include <queue>
using namespace std;
int arr[101][101]; 
int visit[101];
int ans=0, n, m;

void bfs(int num) {
	queue <int> q;
	visit[num] = 1;

	q.push(num);
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 1 ; i <= n; i++) {
			if (arr[front][i] && !visit[i]) {
				q.push(i);
				visit[i] = 1;
				ans++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		arr[num1][num2] = arr[num2][num1] = 1;
	}

	bfs(1);

	cout << ans;

	return 0;
}