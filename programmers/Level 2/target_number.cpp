//programmers Level 2: 타겟 넘버
//2021-10-12
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int idx) {
    if(numbers.size() == idx) {
        if(sum == target) answer++;
        return;
    }
    
    dfs(numbers, target, sum + numbers[idx], idx + 1);
    dfs(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    
    return answer;
}

int main() {
    int answer = solution({1, 1, 1, 1, 1}, 3);
    cout << answer;

    return 0;
}