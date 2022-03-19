/*
programmers Level 1: 최대공약수와 최소공배수
2022-03-19
*/
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int res = gcd(n, m);
    
    answer.push_back(res); // 최대공약수
    answer.push_back(n * m / res); // 최소공배수
    
    return answer;
}