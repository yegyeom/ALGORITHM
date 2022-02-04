/*
BOJ 2529번: 부등호
DATE: 2021-03-04
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10
using namespace std;

int k;
int num[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector <int> maxNum, minNum;
char arr[9];

int check(vector<int> &v){
    for(int i = 0 ; i < k ; i++){
        if(arr[i] == '<' && v[i] > v[i+1]) return 1;
        else if(arr[i] == '>' && v[i] < v[i+1]) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k;

    for(int i = 0 ; i < k ; i++) cin >> arr[i];

//max
    for(int i = 9 ; i >= 9-k ; i--) maxNum.push_back(i);

    while(1){
        if(check(maxNum)){
            prev_permutation(maxNum.begin(), maxNum.end());
        }
        else break;
    }

//min
    for(int i = 0 ; i <= k ; i++) minNum.push_back(i);

    while(1){
        if(check(minNum)){
            next_permutation(minNum.begin(), minNum.end());
        }
        else break;
    }

    for(int i = 0 ; i < k+1 ; i++) cout << maxNum[i];
    cout << '\n';
    for(int i = 0 ; i < k+1 ; i++) cout << minNum[i];
    cout << '\n';

    return 0;
}