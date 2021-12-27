/*
programmers Level 2: 카펫
2021-12-27
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int h = 3, w;
    
    while(1) {
        w = (brown + yellow) / h;
        
        if((h - 2) * (w - 2) == yellow) break;
        h++;
    }
    
    answer.push_back(w);
    answer.push_back(h);
    
    return answer;
}