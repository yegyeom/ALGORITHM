/*
BOJ 1976��: ���� ����
DATE: 2021-02-08
Union-Find
*/
#include <iostream>
#define MAX 200
using namespace std;

int arr[MAX][MAX];

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

//���� �׷����� ���ϴ��� Ȯ��
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

    int parent[n+1], dst[m];
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1 || i==j) //���� �θ� ��带 ��������
                unionParent(parent, i+1, j+1); 
        }
    }

    for(int i = 0 ; i < m ; i++){
        cin >> dst[i];
        if(i > 0){
            if(!findParent(parent, dst[i-1], dst[i])){
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}