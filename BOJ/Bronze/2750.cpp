//BOJ 2750번: 수 정렬하기
//2021-04-12
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, tmp;
    cin >> n;

    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    for(int i = n - 1 ; i > 0 ; i--){
        for(int j = 0 ; j < i ; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}