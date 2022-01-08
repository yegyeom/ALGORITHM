/*
BOJ 18353번: 병사 배치하기
2022-01-08
Longest Increasing Subsequence
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++) {
        cin >> num;
        
        if(i == 0 || num < v.back()) v.push_back(num);
        else if(num > v.back()){
            for(int j = 0 ; j < v.size() ; j++){
                if(v[j] == num) break;
                else if(v[j] < num){
                    v[j] = num;
                    break;
                }
            }
        }
    }

    cout << n - v.size();

    return 0;
}