/*
BOJ 17073��: ���� ���� ����
DATE: 2021-01-21
*/
#include <iostream>
#include <queue>
#define NODE_MAX 500000

using namespace std;

int edge[NODE_MAX] = { 0, };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    double w, leaf=0;
    cin >> n >> w;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edge[u - 1]++;
        edge[v - 1]++;
    }

    for (int i = 1 ; i < n; i++) { 
        if (edge[i] == 1) //�θ� ���͸� ���� �Ǿ��ٸ� leaf
            leaf++;
    }

    cout << fixed; //�Ҽ��� ����
    cout.precision(10); //�Ҽ��� 10�ڸ�
    cout << w / leaf;

    return 0;
}