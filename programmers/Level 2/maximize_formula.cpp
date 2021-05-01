//programmers Level 2 : Maximize formula
//2020 KAKAO Internship
//2021-04-30
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<string> op, new_exp, cp;
priority_queue<long long> pq;
int n;
long long pArr[3] = {0,};
bool check[4] = {false,};

void permutation(int depth){
    if(depth == n){
        long long num;
        
        for(int i = 0 ; i < n ; i++){ //연산자 우선순위대로
            for(int j = 0 ; j < new_exp.size() ; j++){
                if(new_exp[j] == op[pArr[i] - 1]){ //연산자
                    if(new_exp[j] == "+")
                        num = stoll(new_exp[j-1]) + stoll(new_exp[j+1]);  
                    else if(new_exp[j] == "-")
                        num = stoll(new_exp[j-1]) - stoll(new_exp[j+1]);
                    else if(new_exp[j] == "*")
                        num = stoll(new_exp[j-1]) * stoll(new_exp[j+1]);
                    
                    new_exp.insert(new_exp.begin() + (j+2), to_string(num));
                    new_exp.erase(new_exp.begin() + (j-1), new_exp.begin() + (j + 2));
                    
                    j = -1;
                }
            }
        }
        
        num = stoll(new_exp[0]);
        pq.push(abs(num));
        
        new_exp = cp;
        
        return;
    }
    
    for(int i = 1 ; i <= n ; i++){
        if(!check[i]){
            check[i] = true;
            pArr[depth] = i;
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;
    int plus=0, minus=0, mul=0;
    string tmp;
    
    for(int i = 0 ; i < expression.length() ; i++){
        if(expression[i] != '*' && expression[i] != '+' && expression[i] != '-'){
            tmp += expression[i];
            if(i == expression.length() - 1)
                new_exp.push_back(tmp);
        }
        else{
            new_exp.push_back(tmp);
            tmp = expression[i];
            new_exp.push_back(tmp);
            tmp = "";
        }
        
        if(expression[i] == '+' && plus == 0){
                op.push_back("+"); plus++;
        }
        else if(expression[i] == '-' && minus == 0){
            op.push_back("-"); minus++;
        }
        else if(expression[i] == '*' && mul == 0){
            op.push_back("*"); mul++;
        }
    }
    
    cp = new_exp;
    n = op.size(); //식에 존재하는 연산자 종류의 개수
    
    permutation(0);
    answer = pq.top();
    
    return answer;
}

int main(){
    long long ans;
    ans = solution("100-200*300-500+20");

    cout << ans;

    return 0;
}