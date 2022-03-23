/*
programmers Level 1: 완주하지 못한 선수
2022-03-23
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0 ; i < participant.size() ; i++){
        if(completion[i] != participant[i] || i == participant.size() - 1){
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}