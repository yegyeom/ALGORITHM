/*
BOJ 2623번: 음악프로그램
DATE: 2021-03-04
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    int inDegree[n+1] = {0,}, result[n+1];
    vector<int> a[n+1];
    queue<int> q;

    for(int i = 0 ; i < m ; i++){
        int num; cin >> num;
        int arr[num];
        for(int j = 0 ; j < num ; j++){
            cin >> arr[j];
        }
        for(int k = 1 ; k < num ; k++){
            a[arr[k-1]].push_back(arr[k]);
            inDegree[arr[k]]++;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(inDegree[i] == 0) q.push(i);
    }

    for(int i = 1 ; i <= n ; i++){
        if(q.empty()){
            cout << 0;
            return 0;
        }
        int front = q.front();
        q.pop();
        result[i] = front;
        for(int i = 0 ; i < a[front].size() ; i++){
            int next = a[front][i];
            if(--inDegree[next] == 0) 
                q.push(next);
        }
    }
//
    for(int i = 1 ; i <= n ; i++){
        cout << result[i] << "\n";
    }

    return 0;
}