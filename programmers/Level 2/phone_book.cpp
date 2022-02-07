/*
programmers Level 2: 전화번호 목록
DATE: 2022-02-07
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    string cmpStr = phone_book[0];
    
    for(int i = 1 ; i < phone_book.size() ; i++) {
        string subStr = phone_book[i].substr(0, cmpStr.length());
        
        if(cmpStr == subStr) {
            answer = false;
            break;
        }
        
        cmpStr = phone_book[i];
    }
    
    return answer;
}