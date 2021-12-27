// programmers Level 2: 가장 큰 수
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string &a, string &b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int i = 0 ; i < numbers.size() ; i++) v.push_back(to_string(numbers[i]));
    sort(v.begin(), v.end(), cmp);

    for(int i = 0 ; i < v.size() ; i++) answer += v[i];
    answer = answer.front() == '0' ? "0" : answer;
    
    return answer;
}