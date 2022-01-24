//BOJ 2805번: 나무 자르기
//2021-05-25
//Binary Search
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m, max=-1;
    cin >> n >> m;

    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    long long start = 0;
    long long end = arr[n - 1];
    long long mid;

    while(start <= end){
        long long sum = 0;
        mid = (start + end) / 2;

        for(int i = 0 ; i < n ; i++){
            if(arr[i] - mid > 0)
                sum += arr[i] - mid;
        }

        if(sum >= m){
            start = mid + 1;
            if(mid > max)
                max = mid;
        }
        else{
            end = mid - 1;
        }

    }

    cout << max;
    
    return 0;
}