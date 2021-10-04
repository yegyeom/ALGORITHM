//programmers Level 2: 기능개발
//2021-10-05
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0 ; i < progresses.size() ; i++) {
        if((100 - progresses[i]) % speeds[i] == 0) 
            q.push((100 - progresses[i]) / speeds[i]);
        else q.push((100 - progresses[i]) / speeds[i] + 1);
    }
    
    while(!q.empty()) {
        int cnt = 1;
        int cur = q.front();
        q.pop();
        
        while(cur >= q.front() && !q.empty()) {
            q.pop();
            cnt++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}

int main() {
    vector<int> answer = solution({93, 30, 55}, {1, 30, 5});

    for(int i = 0 ; i < answer.size() ; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}