/*
programmers Level 3: 입국심사
이분탐색
2021-12-19
*/
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 1e18
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = MAX;
    long long start = 0, end = MAX, mid, sum;
    
    sort(times.begin(), times.end());
    
    while(start <= end) {
        sum = 0;
        mid = (start + end) / 2;
        
        for(int i = 0 ; i < times.size() ; i++) sum += mid / times[i];
        
        if(sum >= n) {
            end = mid - 1;
            answer = min(mid, answer);
        }
        else {
            start = mid + 1;
        }
    }
    
    return answer;
}

int main() {
    long long answer = solution(6, {7, 10});
    cout << answer;
}