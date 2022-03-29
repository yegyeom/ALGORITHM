/*
programmers Level 2: 메뉴 리뉴얼
date: 2022-03-29
*/
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m; // 조합, 개수
    
    for(string i : orders){
        sort(i.begin(), i.end());
        
        for(int j : course){
            if(i.length() < j) continue;
            
            vector<bool> tmp(i.length(), true);
            for(int k = 0 ; k < j ; k++) tmp[k] = false;
            
            do{ 
                string str;
                
                for(int k = 0 ; k < tmp.size() ; k++){
                    if(!tmp[k]) str += i[k];
                }
                
                m[str]++;
            }while(next_permutation(tmp.begin(), tmp.end()));
        }
    }
    
    int arr[course.back() + 1];
    fill(arr, arr + course.back() + 1, 0);
    
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto i : v){
        if(i.second >= arr[i.first.length()] && i.second > 1) {
            arr[i.first.length()] = i.second;
            answer.push_back(i.first);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}