/*
programmers Level 1: 예산
date: 2022-03-30
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0, sum = 0;
    
    sort(d.begin(), d.end());
    
    for(int i = 0 ; i < d.size() ; i++) {
        if((sum += d[i]) <= budget) {
            answer++;
        }
    }
    
    return answer;
}