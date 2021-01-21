#include <iostream>
#include <vector>
#include <string.h>
#define NODE 10001

using namespace std;

bool visited[NODE] = { false, };
int n, next_node, diameter = 0;
vector<pair <int, int>> tree[NODE];

void dfs(int node, int weight) {
    if(weight > diameter){
        diameter = weight;
        next_node = node;
    }

    for (int i = 0; i < tree[node].size(); i++) {
        if (!visited[tree[node][i].first]) {
            visited[tree[node][i].first] = true;
            dfs(tree[node][i].first, weight + tree[node][i].second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        tree[p].push_back(make_pair(c, w));
        tree[c].push_back(make_pair(p, w));
    }

    visited[1] = true;
    dfs(1, 0);

    memset(visited, false, NODE);
    visited[next_node] = true;
    dfs(next_node, 0);

    cout << diameter;
    return 0;
}