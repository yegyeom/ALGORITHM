/*
programmers Level 2: 괄호 변환
date: 2022-04-29
*/
#include <string>
#include <stack>
using namespace std;

int isBalanced(string str){ // 균형잡힌 괄호 문자열
    int left = 0, right = 0, ret = -1;
    
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '(') left++;
        else right++;
        
        if(left == right) return i;
    }
}

bool isCorrect(string str){ // 올바른 괄호 문자열
    stack<char> s;
    
    for(int i = 0 ; i < str.length() ; i++) {
        if(s.empty() || str[i] == '(') s.push(str[i]);
        else if(s.top() == '(') s.pop();
    }

    if(!s.empty()) return false;
    else return true;
}

string solution(string p) {
    string answer = "";
    
    if(p == "") return answer;
    if(isBalanced(p) != -1 && isCorrect(p)) return p;
        
    while(1){
        int idx = isBalanced(p);
        
        string u = p.substr(0, idx + 1);
        string v = p.substr(idx + 1);
        
        if(isCorrect(u)){
            answer += u;
            p = v;
            continue;
        }
        
        string tmp = "(";
        tmp += solution(v) + ")";
            
        for(int i = 1 ; i < u.length() - 1 ; i++){ // u의 첫 번째와 마지막 문제는 제외
            if(u[i] == '(') tmp += ")";
            else tmp += "(";
        }
            
        answer += tmp;
        break;
    }
    
    return answer;
}