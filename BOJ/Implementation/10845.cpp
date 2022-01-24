/*
BOJ 10845번: 큐
2021-03-30
*/
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    queue <int> q;
    int num;

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;

        if(str == "push"){
            cin >> num;
            q.push(num);
        } 
        else if(str == "pop"){
            if(q.empty())
                num = -1;
            else{
                num = q.front();
                q.pop();
            }
            cout << num << "\n";
        }
        else if(str == "size"){
            cout << q.size() << "\n";
        }
        else if(str == "empty"){
            cout << q.empty() << "\n";
        }
        else if(str == "front"){
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        } 
        else if(str == "back"){
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }
    
    return 0;
}