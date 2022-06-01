/*
programmers Level 2: 짝지어 제거하기
date: 2022-06-01
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    
    for(auto i : s){
        if(st.empty() || st.top() != i) st.push(i);
        else st.pop();
    }
    
    if(st.empty()) answer = 1;
    else answer = 0;
    
    return answer;
}