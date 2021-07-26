//BOJ 10828번: 스택
//2021-03-30
#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    stack <int> s;
    int n, num;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;

        if(str == "push"){
            cin >> num;
            s.push(num);
        } 
        else if(str == "pop"){
            if(s.empty())
                num = -1;
            else{
                num = s.top();
                s.pop();
            }
            cout << num << "\n";
        }
        else if(str == "size"){
            cout << s.size() << "\n";
        }
        else if(str == "empty"){
            cout << s.empty() << "\n";
        }
        else if(str == "front"){
            if(s.empty())
                cout << -1 << "\n";
            else
                cout << s.top() << "\n";
        } 
        else if(str == "top"){
            if(s.empty())
                cout << -1 << "\n";
            else
                cout << s.top() << "\n";
        }
    }
    
    return 0;
}
