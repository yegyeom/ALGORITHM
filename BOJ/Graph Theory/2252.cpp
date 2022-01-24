//BOJ 2252번: 줄 세우기
//2021-07-12
//Topology Sort
#include <iostream>
#include <queue>
#include <vector>
#define MAX 100000
using namespace std;

int n, inDegree[MAX];
vector<int> v[MAX];

void topologySort(){
    int result[n];
    queue<int> q;

    for(int i = 1 ; i <= n ; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    for(int i = 0 ; i < n ; i++){
        int x = q.front();
        q.pop();
        result[i] = x;

        for(int j = 0 ; j < v[x].size() ; j++){
            int y = v[x][j];
            if(--inDegree[y] == 0) q.push(y);
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << result[i] << " ";
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, num1, num2;
    cin >> n >> m;
    
    for(int i = 0 ; i < m ; i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        inDegree[num2]++;
    }

    topologySort();

    return 0;
}