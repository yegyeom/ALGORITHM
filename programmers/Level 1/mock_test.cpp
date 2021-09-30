//programmers Level 1: 모의고사
//2021-09-30
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> vec1 = {1, 2, 3, 4, 5}, vec2 = {2, 1, 2, 3, 2, 4, 2, 5}, vec3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> ans(3), answer;
    int ans1 = 0, ans2 = 0, ans3 = 0;
    
    for(int i = 0 ; i < answers.size() ; i++){
        if(vec1[i % vec1.size()] == answers[i]) ans[0]++;
        if(vec2[i % vec2.size()] == answers[i]) ans[1]++;
        if(vec3[i % vec3.size()] == answers[i]) ans[2]++;
    }

    int max_score = max(max(ans[0], ans[1]), ans[2]);
    
    for(int i = 0 ; i < 3 ; i++){
        if(ans[i] == max_score) answer.push_back(i + 1);
    }
    
    return answer;
}

int main() {
    vector<int> answer = solution({1, 3, 2, 4, 2});
    
    for(int i = 0 ; i < answer.size() ; i++) {
        cout << answer[i];
    }

    return 0;
}