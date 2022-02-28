/*
programmers Level 2: 위장
date: 2022-02-28
*/
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    for(vector<string> v : clothes) m[v[1]] += 1;
    
    for(auto i : m) answer *= i.second + 1; // +1: 해당 종류를 입지 않는 경우 추가
    
    return answer - 1; // 아무 옷도 입지 않은 경우 제외
}