//programmers Level 3 : Bad user
//2019 KAKAO Winter Internship
//2021-05-08
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
set<set<int>> s;

void dfs(int depth, vector<int> list){
    if(depth == v.size()){
        set<int> tmp;
        for(int i = 0 ; i < list.size() ; i++){
            tmp.insert(list[i]);
        }
        s.insert(tmp);
        return ;
    }

    for(int i = 0 ; i < v[depth].size() ; i++){
        auto it = find(list.begin(), list.end(), v[depth][i]);
        if(it != list.end()){
            continue;
        }
        list.push_back(v[depth][i]);
        dfs(depth + 1, list);
        list.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<int> tmp;
    bool flag;
    
    for(int i = 0 ; i < banned_id.size() ; i++){
        for(int j = 0 ; j < user_id.size() ; j++){
            if(user_id[j].length() != banned_id[i].length())
                continue;

            flag = true;
            
            for(int k = 0 ; k < banned_id[i].length() ; k++){
                if(banned_id[i][k] != '*'){
                    if(banned_id[i][k] != user_id[j][k]){
                        flag = false;
                        break;
                    }
                }
            }
            
            if(flag){
                tmp.push_back(j);
            }
        }
        v.push_back(tmp);
        tmp.clear();
    }

    dfs(0, tmp);
    answer = s.size();

    return answer;
}

int main(){
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "*rodo", "******", "******"};

    int ans = solution(user_id, banned_id);
    cout << ans;

    return 0;
}