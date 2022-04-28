/*
programmers Level 1: 체육복
date: 2021-04-28
update: 2022-04-28
*/
#include <string>
#include <vector>
using namespace std;

int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(auto i : lost) arr[i] -= 1;
    for(auto i : reserve) arr[i] += 1;
    
    for(int i = 1 ; i < n ; i++){
        if(arr[i] == -1){
            if(arr[i-1] == 1) arr[i] = arr[i-1] = 0;
            else if(arr[i+1] == 1) arr[i] = arr[i+1] = 0;
        }
    }
    
    for(int i = 1 ; i <= n ; i++){
        if(arr[i] > -1) answer++;
    }
    
    return answer;
}