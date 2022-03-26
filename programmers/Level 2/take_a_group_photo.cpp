/*
programmers Level 2: 단체사진 찍기
2017 KAKAO CODE
DATE: 2021-05-24
UPDATE: 2022-03-26
*/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string str = "ACFJMNRT";

    do{
        bool flag = true;
        
        for(int i = 0 ; i < data.size() ; i++){
            char ch1 = data[i][0];
            char ch2 = data[i][2];
            
            int idx1 = find(str.begin(), str.end(), ch1) - str.begin();
            int idx2 = find(str.begin(), str.end(), ch2) - str.begin();
            
            int diff = abs(idx1 - idx2) - 1;
            int value = data[i][4] - '0';
            
            if(data[i][3] == '=' && diff != value){
                flag = false;
                break;
            }
            else if(data[i][3] == '>' && diff <= value){
                flag = false;
                break;
            }
            else if(data[i][3] == '<' && diff >= value){
                flag = false;
                break;
            }
        }
        
        if(flag) answer++;
    }
    while(next_permutation(str.begin(), str.end()));
    
    return answer;
}