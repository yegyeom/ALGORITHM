#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[101][101];

void bfs(int num){
    bool visited[n] = {false, };
    queue<int> q;

    q.push(num);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0 ; i < n ; i++){
            if(arr[cur][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
                arr[num][i] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j]; 
        }
    }

    for(int i = 0 ; i < n ; i++){
        bfs(i);
    }

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << " "; 
        }
        cout << "\n";
    }

    return 0;
}