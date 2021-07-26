//BOJ 2161번: 카드1
//2021-03-30
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    queue <int> q;

    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        q.push(i);
    }

    while(!(q.size() == 1)){
        cout << q.front() << " ";
        q.pop();

        q.emplace(q.front()); 
        q.pop();
    }

    cout << q.front();

    return 0;
}