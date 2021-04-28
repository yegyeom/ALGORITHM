//programmers Level 1: K번째수
//정렬
//2021-04-28
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
   
    for(int i = 0 ; i < commands.size() ; i++){
        vector<int> tmp;
   
        int c1 = commands[i][0];
        int c2 = commands[i][1];
        int c3 = commands[i][2];
        
        tmp.clear();
        tmp.assign(array.begin() + (c1-1), array.begin() + c2);
        
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[c3 - 1]);
    }
    
    return answer;
}