//programmers Level 3 : Jewelry shopping
//2020 KAKAO Internship
//2021-05-02
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> list; 
    map<string, int> m;
    set<string> s;
    int n, min=100001, ans_start=0, ans_end=0, start=0, end=0;
    
    list = gems;
    sort(list.begin(), list.end());
    list.erase(unique(list.begin(), list.end()), list.end());
    n = list.size();
    
    while(true){
        if(s.size() == n){
            int dst = end - start;
            
            if(dst < min){
                min = dst;
                ans_start = start + 1;
                ans_end = end;
            }
            
            m[gems[start]]--;
            start++;
            
            if(m[gems[start - 1]] == 0){
                s.erase(gems[start - 1]);
            }
        }
        else if(end == gems.size()){
            break;
        }
        else if(s.size() < n){
            s.insert(gems[end]);
            m[gems[end]]++;
            end++;
        }
    }
    
    answer.push_back(ans_start);
    answer.push_back(ans_end);
    
    return answer;
}

int main(){
    vector<string> gems = {"DIA","EM","EM","RUB","DIA"};
    vector<int> answer;

    answer = solution(gems);

    for(int i = 0 ; i < answer.size() ; i++)
        cout << answer[i] << " ";
}