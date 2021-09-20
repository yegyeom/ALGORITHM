//programmers Level 1 : 신규 아이디 추천
//2021 KAKAO BLIND RECRUITMENT
//2021-09-20
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string tmp;
    
    //step 1
    for(int i = 0 ; i < new_id.length() ; i++) {
        if(isupper(new_id[i])) {
            new_id[i] = tolower(new_id[i]);
        }
    }
    
    //step 2
    for(int i = 0 ; i < new_id.length() ; i++) {
        if(islower(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') tmp += new_id[i];
    }
    
    new_id = tmp;
    tmp.clear();
    
    //step 3
    for(int i = 0 ; i < new_id.length() ; i++) {
        if(new_id[i] == '.') {
            if(new_id[i - 1] != '.') tmp += new_id[i];
        }
        else tmp += new_id[i];
    }
    
    new_id = tmp;
    tmp.clear();
    
    //step 4
    for(int i = 0 ; i < new_id.length() ; i++) {
        if(new_id[0] == '.') new_id = new_id.substr(1, new_id.length() - 1);
        if(new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);
    }
    
    //step 5
    if(new_id.length() == 0) new_id = 'a';
    
    //step 6
    if(new_id.length() > 15) {
        new_id = new_id.substr(0, 15);
        if(new_id[14] == '.') new_id = new_id.substr(0, 14);
    }
    
    //step 7
    if(new_id.length() < 3){
        char ch = new_id[new_id.length() - 1];
        while(new_id.length() != 3) new_id += ch;
    }
    
    string answer = new_id;

    return answer;
}

int main() {
    string answer = solution("...!@BaT#*..y.abcdefghijklm");
    cout << answer;

    return 0;
}