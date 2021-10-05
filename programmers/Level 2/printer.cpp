//programmers Level 2: 프린터
//2021-10-06
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int, vector<int>> pq;
    queue<pair<int, int>> q; 
    vector<int> v;
    int answer = 0;

    for(int i = 0 ; i < priorities.size() ; i++) {
        q.push(make_pair(priorities[i], i)); //중요도, 문서
        pq.push(priorities[i]);
    }
    
    int max = pq.top();
    
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        
        if(cur.first < max) {
            while(cur.first != max) {
                q.push(q.front());
                q.pop();
                cur = q.front();
            }
        }
        else {
            v.push_back(cur.second);
            q.pop(); pq.pop();
            max = pq.top();
        }
    }
    
    answer = (find(v.begin(), v.end(), location) - v.begin()) + 1;
    
    return answer;
}

int main() {
    int answer = solution({2, 1, 3, 2}, 2);
    cout << answer;

    return 0;
}