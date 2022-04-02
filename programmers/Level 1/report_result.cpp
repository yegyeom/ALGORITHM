/*
programmers Level 1: 신고 결과 받기
2022 KAKAO BLIND RECRUITMENT
DATE: 2022-04-02
*/
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2) {
    return p1.second < p2.second;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, int> id, mail; 
    map<string, set<string>> all_report; // 신고 당한 유저, 신고한 유저의 집합
    
    for(auto i : report){
        int idx = i.find(' ');
        string a = i.substr(0, idx); // 신고한 ID
        string b = i.substr(idx + 1); // 신고당한 ID

        if(all_report[b].find(a) != all_report[b].end()) continue; 
        all_report[b].insert(a);
        id[b]++; // b가 신고당한 횟수
    }
    
    for(int i = 0 ; i < id_list.size() ; i++) mail[id_list[i]] = 0;
    
    for(auto i : id){
        string user_id = i.first;
        int cnt = i.second;
        
        if(cnt >= k) {
            for(auto j : all_report[user_id]) mail[j]++;
        }
    }
    
    for(auto i : mail) {
        int idx = find(id_list.begin(), id_list.end(), i.first) - id_list.begin();
        answer[idx] = i.second;
    }
    
    return answer; 
}