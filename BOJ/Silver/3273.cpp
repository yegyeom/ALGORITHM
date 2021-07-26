//BOJ 3273번: 두 수의 합
//2021-06-01
//Two Pointers
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;

    int start = 0, end = n - 1, sum = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cin >> x;

    while (start < end) {
        if (arr[start] + arr[end] == x) {
            ans++;
            start++;
        }
        else if (arr[start] + arr[end] > x) {
            end--;
        }
        else {
            start++;
        }
    }

    cout << ans;

    return 0;
}