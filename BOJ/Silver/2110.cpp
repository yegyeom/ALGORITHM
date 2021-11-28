//BOJ 2110번: 공유기 설치
//2021-07-01
//2021-11-29
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c, start, end, mid, ans=-1;
    cin >> n >> c;

    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    start = 1;
    end = arr[n-1];

    while(end - start >= 0){
        int cnt=1, idx = 0; 
        mid = (end + start) / 2; //공유기 사이의 거리가 최소 x 이상일 때, 가능한 최대의 x값

        for(int i = 1 ; i < n ; i++){
            if(arr[i] - arr[idx] >= mid) {
                idx = i; // 공유기 설치
                cnt++;
            }
        }

        //공유기의 개수가 c보다 작으면: 최소 거리의 최댓값 감소
        //크거나 같으면: 최소 거리의 최댓값 증가
        if(cnt < c){ 
            end = mid - 1;
        }
        else if(cnt >= c){
            start = mid + 1;
            ans = max(ans, mid);
        }

    }

    cout << ans;

    return 0;
}