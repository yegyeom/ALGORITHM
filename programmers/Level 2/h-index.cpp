/*
programmers Level 2: H-index
2021-12-26
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int num = citations.size();
    
    sort(citations.begin(), citations.end()); 
    
    for(int i = num ; i >= 0 ; i--) {
        int index = lower_bound(citations.begin(), citations.end(), i) - citations.begin();

        if(i <= num - index) {
            answer = i;
            break;
        }
    }
    
    return answer;
}

int main(){
    int answer = solution({3, 0, 6, 1, 5});
    cout << answer;

    return 0;
}