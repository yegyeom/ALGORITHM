/*
BOJ 9012번: 괄호
DATE: 2022-04-05
*/
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        stack<char> s;
        string str;
        cin >> str;

        for(int i = 0 ; i < str.length() ; i++) {
            if(s.empty() || str[i] == '(') s.push(str[i]);
            else if(s.top() == '(') s.pop();
        }

        if(!s.empty()) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}