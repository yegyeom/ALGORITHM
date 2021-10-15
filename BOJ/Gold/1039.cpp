//BOJ 1039번: 교환
//2021-10-16
#include <iostream>
#include <queue>
#include <set>
using namespace std;

void swap(string &str, int left, int right){
    char tmp = str[left];
    str[left] = str[right];
    str[right] = tmp;
}

int main(){
    queue<string> q;
    int n, k, ans = -1;
    cin >> n >> k;

    q.push(to_string(n));

    for(int i = 0 ; i < k ; i++){ 
        set<string> s; 
        int qsz = q.size();

        for(int j = 0 ; j < qsz ; j++){
            string cur = q.front();
            q.pop();

            if(s.count(cur) > 0) continue; //set에 존재하면 패스 (중복 제거) 
            else(s.insert(cur));

            for(int s = 0 ; s < cur.length() ; s++){ //left
                for(int e = s + 1 ; e < cur.length() ; e++){ //right
                    if(!(s == 0 && cur[e] == '0')){ //바꾼 수가 0으로 시작하면 안되므로
                        swap(cur, s, e);
                        q.push(cur);
                        swap(cur, s, e); // 원래대로
                    }
                }
            }
        }
    }

    while(!q.empty()){
        int num = stoi(q.front());
        ans = max(ans, num);
        q.pop();
    }

    if(ans < 10) //0으로 시작할 때
        cout << -1;
    else
        cout << ans;

    return 0;
    
}