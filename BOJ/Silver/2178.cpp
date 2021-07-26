#include <iostream>
#include <queue>
#define MAX 100

using namespace std;
int n, m;
int maze[MAX][MAX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
bool visited[MAX][MAX] = { false, };

void bfs() {
	queue<pair<int, int>> q;
	pair<int, int> p; //현재 위치

	q.push(make_pair(0, 0));
	visited[0][0] = true;

	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];

			if (p.first + dy[i] < 0 || p.first + dy[i] >= n || p.second + dx[i] < 0 || p.second + dx[i] >= m)
				continue;
			if (nx >= 0 && ny >= 0 && ny < n && nx < m && maze[ny][nx] == 1 && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				maze[ny][nx] = maze[p.first][p.second] + 1; //거리 구하기
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			maze[i][j] = str[j] - '0';
		}
	}

	bfs();

	cout << maze[n - 1][m - 1];

	return 0;
}