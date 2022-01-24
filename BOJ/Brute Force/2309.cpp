/*
BOJ 2309번: 일곱 난쟁이
2021-05-18
Brute Force
*/
#include <iostream>
#include <algorithm>
#define n 9
using namespace std;

int main(){
    int arr[n], sum=0;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+n);

    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(sum - arr[i] - arr[j] == 100){
                for(int k = 0 ; k < n ; k++){
                    if(i == k || j == k)
                        continue;
                    else
                        cout << arr[k] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}