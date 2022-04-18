/*
programmers Level 2: 순위 검색
2021 KAKAO BLIND RECRUITMENT
2022-04-18
*/
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<int>> m; 

vector<string> split(string str, char del){
    vector<string> ret;
    istringstream iss(str);
    string buffer;
    
    while(getline(iss, buffer, del)) ret.push_back(buffer);
    
    return ret;
}

void getCombination(vector<string> v){
    for(int i = 0 ; i < 16 ; i++){
        string tmp;
            
        for(int j = 0 ; j < 4 ; j++){
            if(i & (1 << j)) tmp += "-";
            else tmp += v[j];
        }
            
        m[tmp].push_back(stoi(v[4]));
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i = 0 ; i < info.size() ; i++){
        vector<string> ret = split(info[i], ' ');
        getCombination(ret); // 해당 info로 만들 수 있는 모든 조합 만들고 점수 삽입
    }
    
    for(auto &i : m){
        sort(i.second.begin(), i.second.end());
    }
    
    for(int i = 0 ; i < query.size() ; i++){
        vector<string> ret = split(query[i], ' ');
        string tmp;
        
        for(int j = 0 ; j < ret.size() - 1 ; j++){
            if(ret[j] == "and") continue;
            tmp += ret[j];
        }
        
        vector<int> scores = m[tmp]; // query 조건을 만족하는 점수들
        
        if(scores.size() == 0) answer.push_back(0);
        else{
            int score = stoi(ret[7]);
            int idx = lower_bound(scores.begin(), scores.end(), score) - scores.begin();
            
            answer.push_back(scores.size() - idx);
        }
    }
    
    return answer;
}