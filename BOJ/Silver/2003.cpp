//BOJ 2003번: 수들의 합 2
//2021-06-01
//Two Pointers
#include <iostream>
#define MAX 10001
using namespace std;

int arr[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int start=0, end=0, sum=0, answer=0;
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    while(end <= n){
        if(sum < m){
            sum += arr[end];
            end++;
        }
        else if(sum >= m){
            sum -= arr[start];
            start++;
        }

        if(sum == m){
            answer++;
        }
    }

    cout << answer;

    return 0;
}