/*
BOJ 2461번: 대표 선수
DATE: 2022-01-18
Two pointer
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<pair<int,int>> total;
    int n, m, input;
    int start, end, diff, classNum = 0;
    int min = 1e9;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> input;
            total.push_back({input, i});
        }
    }

    sort(total.begin(), total.end());

    start = 0; end = 0;
    vector<int> check(n);

    while(end < n * m) {
        // 한 반에서 한 명씩 선발될 때까지 end 증가
        if(check[total[end].second] == 0) classNum++;
        check[total[end].second]++;
        end++;

        while(classNum == n){ 
            diff = total[end - 1].first - total[start].first;
            if(diff < min) min = diff;
     
            check[total[start].second]--;
            if(check[total[start].second] == 0) classNum--;
            start++;
        }
    }

    cout << min;

    return 0;
}