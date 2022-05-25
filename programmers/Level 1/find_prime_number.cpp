/*
programmers Level 1: 소수 찾기
date: 2022-05-26
*/
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int isNotPrime[1000001];

int solution(int n) {
    int answer = 0;
    
    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(!isNotPrime[i]) {
            for(int j = i * i ; j <= n ; j += i) isNotPrime[j] = 1;
        }
    }
    
    for(int i = 2 ; i <= n ; i++){
        if(!isNotPrime[i]) answer++;
    }
    
    return answer;
}