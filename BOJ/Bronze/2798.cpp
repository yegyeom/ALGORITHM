//BOJ 2798번: 블랙잭
//2021-05-18
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, sum, maximum = -1;
    cin >> n >> m;

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    for(int i = 0 ; i < n-2 ; i++){
        for(int j = i + 1 ; j < n-1 ; j++){
            for(int k = j + 1 ; k < n ; k++){
                sum = arr[i] + arr[j] + arr[k];
                if(sum <= m && sum > 0){
                    maximum = max(sum, maximum);
                }
            }
        }
    }

    cout << maximum;

    return 0;
}