//BOJ 11438번: LCA
//2021-07-13
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

vector<int> v[MAX];
int depth[MAX], parent[MAX];
int n, m;

void bfs(int parentNode, int curDepth){
    queue<int> q;
    q.push(parentNode);

    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0 ; i < qsize ; i++){
            int curNode = q.front();
            depth[curNode] = curDepth;
            q.pop();

            for(int nextNode : v[curNode]){
                if(depth[nextNode] == 0){
                    parent[nextNode] = curNode;
                    q.push(nextNode);
                }
            }
        }
        curDepth++;
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> n;
    
    for(int i = 1 ; i < n ; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1, 1);

    cin >> m;

    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;

        //a의 레벨 > b의 레벨
        if(depth[a] < depth[b]) swap(a, b);
        
        while(depth[a] != depth[b]) {
            a = parent[a]; //레벨이 같아질 때까지 갱신
        }
        while(a != b){
            a = parent[a];
            b = parent[b];            
        }

        cout << b << '\n';
    }

    return 0;
}