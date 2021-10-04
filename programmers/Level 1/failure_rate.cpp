//programmers Level 1: 실패율
//2019 KAKAO BLIND RECRUITMENT
//2021-10-04
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool cmp(pair<double, int>a, pair<double, int>b) {
    	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
    
}
vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> res(N);
    vector<int> answer;
    map<int, int> m;
    int total = stages.size(); 
    int max = *max_element(stages.begin(), stages.end());

    sort(stages.begin(), stages.end());
    int idx = 0;
    
    for(int i = 1 ; i <= max ; i++) {
        int cnt = 0;
        for(int j = idx ; j < stages.size() ; j++) {
            if(stages[j] == i) cnt++;
            else {
                idx = j;
                break;
            }
        }
        m.insert({i, cnt});
    }
    
    for(int i = 0 ; i < N ; i++) {
        double n = m[i+1];
        double d = total -= m[i];
        
        if(total <= 0) { //이거 안하면 틀림
            res[i] = make_pair(0, i + 1);
            continue;
        }
        res[i] = make_pair(n / d, i + 1);
    }
    
    sort(res.begin(), res.end(), cmp);
    
    for(int i = 0 ; i < res.size() ; i++) {
        answer.push_back(res[i].second);
    }
    
    return answer;
}

int  main() {
    vector<int> answer = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    
    for(int i = 0 ; i < answer.size() ; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}