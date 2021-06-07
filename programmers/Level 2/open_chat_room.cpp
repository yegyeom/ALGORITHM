//programmers Level 2 : Open chat room
//2019 KAKAO BLIND RECRUITMENT
//2021-05-27
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    string tmp, command, id, name, str;
    int cnt=0;
    
    for(int i = 0 ; i < record.size() ; i++){
        for(int j = 0 ; j < record[i].length() ; j++){
            if(record[i][j] == ' '){
                if(cnt == 0)
                    command = tmp;
                else if(cnt == 1)
                    id = tmp;
                
                cnt++;
                tmp = "";
            }
            else{
                tmp += record[i][j];
            }

            if(j == record[i].length() - 1){
                name = tmp;
                tmp = "";
            }
        }
        cnt = 0;

        if(command == "Leave")
            continue;
        
        m[id] = name;
    }

    for(int i = 0 ; i < record.size() ; i++){
        for(int j = 0 ; j < record[i].length() ; j++){
            if(record[i][j] == ' '){
                if(cnt == 0)
                    command = tmp;
                else if(cnt == 1)
                    id = tmp;
                
                cnt++;
                tmp = "";
            }
            else{
                tmp += record[i][j];
            }

            if(j == record[i].length() - 1){
                if(command == "Leave")
                    id = tmp;
                else
                    name = tmp;
                    
                tmp = "";
            }
        }
        
        cnt = 0;

        if(command == "Enter"){
            str = m[id] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            answer.push_back(str);
        }
        else if(command == "Leave"){
            str = m[id] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            answer.push_back(str);
        }
        
    }
    
    return answer;
}

int main(){
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> answer = solution(record);

    for(int i = 0 ; i < answer.size() ; i++){
        cout << answer[i] << '\n';
    }

    return 0;
}