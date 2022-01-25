/*
BOJ 1806번: 부분합
DATE: 2021-06-01
Two Pointer
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int start=0, end=0, sum=0;
    int length = 100001;
    int n, s;
    cin >> n >> s;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    while(end <= n){
        if(sum >= s){
            int dst = end - start;
            length = min(length, dst);

            sum -= arr[start++];
        }
        else if(sum < s){
            sum += arr[end++];
        }
    }

    if(length == 100001) cout << 0;
    else cout << length;

    return 0;
}