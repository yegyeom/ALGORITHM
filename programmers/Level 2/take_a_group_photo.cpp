//programmers Level 2 : Take a group photo
//2017 KAKAO CODE
//2021-05-24
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<int> v;
    vector<vector<int>> c;
    
    for(int i = 0 ; i < 8 ; i++){
        v.push_back(i+1);
    }

    for(int i = 0 ; i < n ; i++){
        vector<int> tmp;
        int num;

        if(data[i][0] == 'A' || data[i][2] == 'A'){
            num = 1;
            tmp.push_back(num);
        }
        if(data[i][0] == 'C' || data[i][2] == 'C'){
            num = 2;
            tmp.push_back(num);
        }
        if(data[i][0] == 'F' || data[i][2] == 'F'){
            num = 3;
            tmp.push_back(num);
        }
        if(data[i][0] == 'J' || data[i][2] == 'J'){
            num = 4;
            tmp.push_back(num);
        }
        if(data[i][0] == 'M' || data[i][2] == 'M'){
            num = 5;
            tmp.push_back(num);
        }
        if(data[i][0] == 'N' || data[i][2] == 'N'){
            num = 6;
            tmp.push_back(num);
        }
        if(data[i][0] == 'R' || data[i][2] == 'R'){
            num = 7;
            tmp.push_back(num);
        }
        if(data[i][0] == 'T' || data[i][2] == 'T'){
            num = 8;
            tmp.push_back(num);
        }
        
        if(data[i][3] == '='){
            tmp.push_back(0);
        }
        else if(data[i][3] == '<'){
            tmp.push_back(-1);
        }
        else if(data[i][3] == '>'){
            tmp.push_back(1);
        }
        
        tmp.push_back(data[i][4] - '0');
        c.push_back(tmp);
    }

    do{
        int cnt=0;
        
        for(int i = 0 ; i < c.size() ; i++){
            int num1 = find(v.begin(), v.end(), c[i][0]) - v.begin();
            int num2 = find(v.begin(), v.end(), c[i][1]) - v.begin();

            if(c[i][2] == 0){ // =
                if(abs(num1 - num2) == c[i][3] + 1)
                    cnt++;
                else continue;
            }
            else if(c[i][2] == -1){ // <
                if(abs(num1 - num2) <= c[i][3])
                    cnt++;
                else continue;
            }
            else if(c[i][2] == 1){ // >
                if(abs(num1 - num2) - 1 > c[i][3])
                    cnt++;
                else continue;
            }
        }

        if(cnt == n)
            answer++;
            
    }
    while(next_permutation(v.begin(), v.end()));
    
    return answer;
}

int main(){
    vector<string> data = {"N~F=0", "R~T>2"};
    int answer = solution(2, data);

    cout << answer;

    return 0;
}