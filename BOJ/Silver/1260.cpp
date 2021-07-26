//BOJ 1260번: DFS와 BFS
//2021-05-19
#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;
int arr[MAX][MAX];
bool visited[MAX] = { false, };
int n, m, v;

void dfs(int node) {
	visited[node] = true;
	cout << node << " "; 

	for (int i = 1 ; i <= n ; i++) {
		if (arr[node][i] == 1 && visited[i] == false) { 
			dfs(i); 
		}
	}
}

void bfs(int node) {
	queue <int> q;
    
	q.push(node); 
	visited[node] = true; 

	cout << node << " "; 

	while (!q.empty()) { 
        int front = q.front(); 
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[front][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
				cout << i << " "; 
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) { 
		int num1, num2;
		cin >> num1 >> num2;
		arr[num1][num2] = arr[num2][num1] = 1;
	}

    //DFS 
	dfs(v);
	cout << "\n";

	for(int i = 0 ; i < MAX ; i++)
		visited[i] = { false, };

    //BFS 
	//bfs(v); 

	return 0;
}