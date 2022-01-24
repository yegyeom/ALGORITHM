//BOJ 1920번: 수 찾기
//2021-05-25
//Binary Search
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    bool flag = false;
    cin >> n;

    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + n);

    cin >> m;
    for(int i = 0 ; i < m ; i++){
        int num;
        cin >> num;

        int start = 0;
        int end = n - 1;
        int mid = 0;

        while(start <= end){
            mid = (start + end) / 2;

            if(arr[mid] == num){
                cout << 1 << "\n";
                flag = true;
                break;
            }
            else if(arr[mid] < num){
                start = mid + 1;
            }
            else if(arr[mid] > num){
                end = mid - 1;
            }
        }

        if(!flag)
            cout << 0 << "\n";
        else
            flag = false;
    }

    return 0;
}