/*
BOJ 13549번: 숨바꼭질 3
2022-01-12
BFS ver.
*/
#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int mv[3] = {2, -1, 1};
int sec[MAX] = {0, };
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;

    sec[n] = 1; // 0초로 두고 시작하면 이미 방문했어도 방문하지 않은 것으로 판단된다. 따라서 초깃값을 1로 설정하고 답을 출력할 때 -1 해주는 것.
    q.push(n);

    while(!q.empty()){
        int cur = q.front();
        int next;
        q.pop();

        if(cur == k){
            cout << sec[cur] - 1;
            break;
        }

        for(int i = 0 ; i < 3 ; i++){
            bool flag = true;

            if(i > 0) { 
                next = cur + mv[i];
                flag = false;
            }
            else next = cur * mv[i];

            if(next < 0 || next > MAX - 1 || sec[next]) continue;
        
            q.push(next);
            if(!flag) sec[next] = sec[cur] + 1;
            else sec[next] = sec[cur];
        }  
    }

    return 0;
}