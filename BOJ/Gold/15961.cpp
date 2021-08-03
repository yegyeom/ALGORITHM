//BOJ 15961번: 회전 초밥
//2021-08-03
#include <iostream>
#include <algorithm>
using namespace std;

int arr[3000001];
int sushi[3001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d, k, c, cnt=0, ans=-1;
    int start, end, total;
    cin >> n >> d >> k >> c;

    for(int i = 0  ; i < n ; i++)
        cin >> arr[i];
    for(int i = 0 ; i < k ; i++){
        sushi[arr[i]]++;
        if(sushi[arr[i]] == 1) cnt++;
    }

    if(++sushi[c] == 1) cnt++;

    start = 0;
    end = k - 1;

    while(start < n){
        ans = max(ans, cnt);
        end = (end + 1) % n;

        sushi[arr[start]]--;
        if(sushi[arr[start]] == 0) cnt--;

        sushi[arr[end]]++;
        if(sushi[arr[end]] == 1) cnt++;

        start++;
    }

    cout << ans;

    return 0;
}