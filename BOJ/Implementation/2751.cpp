/*
BOJ 2751번: 수 정렬하기 2
DATE: 2021-04-12
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);
  
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}