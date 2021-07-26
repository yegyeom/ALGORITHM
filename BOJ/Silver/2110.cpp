//BOJ 2110번: 공유기 설치
//2021-07-01
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}

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
        int cnt=0, num;
        mid = (end + start) / 2;

        if(mid + arr[0] <= arr[n-1]) {
            num = mid + arr[0];
            cnt++;
        }

        for(int i = 1 ; i < n ; i++){
            if(arr[i] >= num){
                cnt++;
                num = mid + arr[i];
            }
        }

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