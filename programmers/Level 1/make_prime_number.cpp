//programmers Level 1: 소수 만들기
//2021-10-11
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

vector<int> v;
int cArr[3];
int answer = 0;

bool isPrime(int num) {
    if(num < 2) return false;
    
    for(int i = 2 ; i <= sqrt(num) ; i++) {
        if(num % i == 0) return false;
    }
    
    return true;
}

void combination(int depth, int next) {
    if(depth == 3) {
        int sum = 0;
        
        for(int i = 0 ; i < 3 ; i++) sum += cArr[i];
        if(isPrime(sum)) answer++;
        
        return;
    }
    
    for(int i = next ; i <= v.size() ; i++) {
        cArr[depth] = v[i - 1];
        combination(depth + 1, i + 1);
    }
}

int solution(vector<int> nums) {
    v = nums;
    combination(0, 1);
    
    return answer;
}

int main() {
    int answer = solution({1, 2, 3, 4});
    cout << answer;

    return 0;
}