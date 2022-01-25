/*
BOJ 1717번: 집합의 표현
DATE: 2021-02-15
Union-Find
*/
#include <iostream>
using namespace std;

int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    int parent[n+1];
    for(int i = 0 ; i <= n ; i++){
        parent[i] = i;
    }

    for(int i = 0 ; i < m ; i++){
        int x, y, z;
        cin >> x >> y >> z;

        if(x == 0) unionParent(parent, y, z);
        else if(x == 1){
            if(findParent(parent, y, z))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }

    return 0;
}