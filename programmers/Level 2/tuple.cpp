//programmers Level 2 : Tuple
//2019 KAKAO Winter Internship
//2021-05-07
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<vector<int>> tmp1;
    vector<int> answer, tmp2;
    map<int, int> m;
    string ss;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] != '{' && s[i] != '}' && s[i] != ','){ 
            ss += s[i];
        }
        else if(s[i] == ',' && s[i + 1] != '{'){
            tmp2.push_back(atoi(ss.c_str()));
            ss="";
        }
        else if(s[i] == '}' && s[i + 1] != '}'){
            tmp2.push_back(atoi(ss.c_str()));
            tmp1.push_back(tmp2);
            tmp2.clear();
            ss="";
        }
    }
    
    sort(tmp1.begin(), tmp1.end(), cmp);

    for(int i = 0 ; i < tmp1.size() ; i++){
        for(int j = 0 ; j < tmp1[i].size() ; j++){
            if(m[tmp1[i][j]] > 0)
                continue;
            answer.push_back(tmp1[i][j]);
            m[tmp1[i][j]]++;
        }
    }

    return answer;
}

int main(){
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector <int> answer = solution(s);
    
    for(int i = 0 ; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}