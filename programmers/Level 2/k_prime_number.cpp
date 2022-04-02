/*
programmers Level 2: k진수에서 소수 개수 구하기
2022 KAKAO BLIND RECRUITMENT
DATE: 2022-04-02
*/
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int answer = 0;

bool isPrime(long long num){
    if(num < 2) return false;
    
    for(long long i = 2 ; i <= sqrt(num) ; i++){
        if(num % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    string str, tmp = "";
    
    while(n > 0){
        str += n % k + 48;
        n /= k;
    }
    
    reverse(str.begin(), str.end());
    
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '0' && tmp.length() > 0){
            if(isPrime(stoi(tmp))) answer++;
            tmp = "";
        }
        else tmp += str[i];
    }
    
    if(isPrime(stoll(tmp))) answer++;
    
    return answer;
}