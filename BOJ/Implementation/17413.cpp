/*
BOJ 17413번: 단어 뒤집기 2
DATE: 2022-06-06
*/
#include <iostream>
#include <stack>
using namespace std;

stack<char> s;

void print(){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    bool flag = false;

    getline(cin, str);

    for(auto i : str){
        if(i == '<'){
            print();
            cout << i;
            flag = true;
        }
        else if(i == '>'){
            cout << i;
            flag = false;
        }
        else if(flag) cout << i;
        else if(i == ' ') {
            print();
            cout << " ";
        }
        else s.push(i);
    }

    print();

    return 0;
}