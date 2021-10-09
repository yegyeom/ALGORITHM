//programmers Level 2: 소수 찾기
//2021-10-09
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if(num < 2) return false;
    
    for(int i = 2 ; i <= sqrt(num) ; i++) {
        if(num % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<string> v;
    set<int> s;

    sort(numbers.begin(), numbers.end());
    
    do {
        string str;
        
        for(int i = 0 ; i < numbers.size() ; i++) {
            str += numbers[i];
            s.insert(stoi(str));
        }
        
    }while(next_permutation(numbers.begin(), numbers.end()));

    for(auto i : s) {
       if(isPrime(i)) answer++;
    }
    
    return answer;
}

int main() {
    int answer = solution("011");
    cout << answer;

    return 0;
}