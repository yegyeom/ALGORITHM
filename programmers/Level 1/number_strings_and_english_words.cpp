//programmers Level 1: 숫자 문자열과 영단어
//2021 카카오 채용연계형 인턴십
//2021-09-21
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string str;
    
    for(int i = 0 ; i < s.length() ; i++){
        if(!isdigit(s[i])) {
            string tmp;
            
            while(1) {
                if(tmp == "zero") {str += "0"; break;}
                else if(tmp == "one"){ str += "1"; break;}
                else if(tmp == "two") {str += "2"; break;}
                else if(tmp == "three") {str += "3"; break;}
                else if(tmp == "four") {str += "4"; break;}
                else if(tmp == "five") {str += "5"; break;}
                else if(tmp == "six") {str += "6"; break;}
                else if(tmp == "seven") {str += "7"; break;}
                else if(tmp == "eight") {str += "8"; break;}
                else if(tmp == "nine") {str += "9"; break;}
                tmp += s[i++];
            }
            i--;
        }
        else str += s[i];
    }
    
    answer = stoi(str);

    return answer;
}

int main(){
    int answer = solution("2three45sixseven");
    cout << answer;

    return 0;
}