/*
programmers Level 2: 영어 끝말잇기
DATE: 2022-06-14
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, int> word;

    for(int i = 0 ; i < words.size() ; i++){
        if(word[words[i]] > 0 || (i > 0 && words[i - 1].back() != words[i].front())) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        
        word[words[i]]++;
    }

    return answer;
}