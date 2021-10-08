//programmers Level 1: 가운데 글자 가져오기
//2021-10-08
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = s.length() / 2;
    
    if(s.length() % 2 == 0) {
        //짝수
        answer += s[idx - 1];
        answer += s[idx];
    }
    else {
        //홀수
        answer += s[idx];
    }
    
    return answer;
}