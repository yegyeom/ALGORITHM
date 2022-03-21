/*
programmers Level 1: 나누어 떨어지는 숫자 배열
2022-03-21
*/
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    sort(arr.begin(), arr.end());
    
    for(auto i : arr){
        if(i % divisor == 0) answer.push_back(i);
    }
    
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}