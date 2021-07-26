//BOJ 2512번: 예산
//2021-05-25
//Binary Search
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, sum=0, ans=-1;
    cin >> n;

    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+n);

    cin >> m;

    if(sum <= m){
        cout << arr[n - 1];
    }
    else{
        int start = 0;
        int end = m;
        int mid;

        while(start <= end){
            //mid => Ư���� ���� ���Ѿ�
            sum = 0;
            mid = (start + end) / 2;

            for(int i = 0 ; i < n ; i++){
                if(arr[i] <= mid)
                    sum += arr[i];
                else
                    sum += mid;
            }
            
            cout << "start: " << start << " end: " << end << " [mid: " << mid << "]\n";
            cout << "sum: " << sum << "\n\n";

            if(sum <= m){
                start = mid + 1;
                if(mid > ans) 
                    ans = mid;
            }
            else if(sum > m){
                end = mid - 1;
            }
        }

        cout << ans;

    }

    return 0;
}