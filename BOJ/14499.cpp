//BOJ 14499번: 주사위 굴리기
//2021-07-02
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int dice[6] = {0,};
    int n, m, x, y, k, move, bottom=4, right = 1, front=3, tmp;
    cin >> n >> m >> x >> y >> k;

    int map[n][m];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < k ; i++){
        cin >> move;

        if(move == 1){ //동쪽
            y += 1;
            if(x < 0 || x >= n || y < 0 || y >= m){
                y--;
                continue;
            }
            
            tmp = bottom;
            bottom = right;
            if(tmp % 2 == 0) right = tmp +1;
            else right = tmp - 1;
        }
        else if(move == 2){ //서쪽
            y -= 1;
            if(x < 0 || x >= n || y < 0 || y >= m){
                y++;
                continue;
            }

            tmp = bottom;
            if(right % 2 == 0) bottom = right+1;
            else bottom = right-1;
            right = tmp;
        }
        else if(move == 3){ //북쪽
            x -= 1;
            if(x < 0 || x >= n || y < 0 || y >= m){
                x++;
                continue;
            }

            tmp = bottom;
            if(front % 2 == 0) bottom = front+1;
            else bottom = front - 1;
            front = tmp;
        }
        else if(move == 4){ //남쪽
            x += 1;
            if(x < 0 || x >= n || y < 0 || y >= m){
                x--;
                continue;
            }

            tmp = bottom;
            bottom = front;
            if(tmp % 2 == 0) front = tmp + 1;
            else front = tmp - 1;
        }

        if(map[x][y] == 0){
            map[x][y] = dice[bottom];
        }
        else{
            dice[bottom] = map[x][y];
            map[x][y] = 0;
        }
        
        if(bottom % 2 == 0) cout << dice[bottom+1] << '\n';
        else cout << dice[bottom-1] << '\n';
    }

    return 0;
}