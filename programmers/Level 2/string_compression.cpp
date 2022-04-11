/*
programmers level 2: 문자열 압축
date: 2022-04-11
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int minVal = s.length(); 
    
    for(int i = 1 ; i <= s.length() / 2 ; i++){
        string left, res;
        int cnt = 0;
        
        for(int j = 0 ; j <= s.length() ; j += i){
            string right = s.substr(j, i);
            
            if(left == right) cnt++;
            else if(cnt > 0){
                string tmp = to_string(cnt + 1) + left;
                right.length() >= i ? res += tmp : res += tmp + right;
                
                cnt = 0;
            }    
            else right.length() == i ? res += left : res += left + right;
            
            left = right;
        }
        
        int leng = res.length();
        minVal = min(minVal, leng);
    }
    
    return minVal;
}