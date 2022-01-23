/*
BOJ 2559번: 수열
DATE: 2022-01-23
Prefix Sum
*/
#include <iostream>
#include <queue>
using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<int> pq;
    int n, k;
    
    cin >> n >> k;

    for(int i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];

        if(i < k) continue;
        pq.push(arr[i] - arr[i - k]);
    }

    cout << pq.top();

    return 0;
}