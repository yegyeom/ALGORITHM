//BOJ 14891번: 톱니바퀴
//2021-07-12
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> number, direction;
int arr[4][8];
int k, ans=0;

void turn_gear(int gear, int turn){
    if(turn == 1){ //Clockwise
        int tmp = arr[gear][7];

        for(int j = 6 ; j >= 0 ; j--){
            arr[gear][j+1] = arr[gear][j];
        }

        arr[gear][0] = tmp;
    }
    else if(turn == -1){ //Counterclockwise
        int tmp = arr[gear][0];

        for(int j = 1 ; j < 8 ; j++){
            arr[gear][j-1] = arr[gear][j];
        }

        arr[gear][7] = tmp;
    }
}

void solve(){
    for(int i = 0 ; i < number.size() ; i++){
        vector<pair<int,int>> v;
        int gear = number[i] - 1;
        int turn = direction[i], next_turn = -turn;

        if(gear == 0){
            for(int j = 1 ; j < 4 ; j++){
                if(arr[j-1][2] == arr[j][6]) break;
                else{
                    v.push_back(make_pair(j, next_turn));
                    next_turn = -next_turn;
                }
            }
        }
        else if(gear == 1){
            if(arr[0][2] != arr[gear][6]){
                turn_gear(0, next_turn);
            }
            for(int j = 2 ; j < 4 ; j++){
                if(arr[j-1][2] == arr[j][6]) break;
                else{
                    v.push_back(make_pair(j, next_turn));
                    next_turn = -next_turn;
                }
            }
        }
        else if(gear == 2){
            if(arr[gear][2] != arr[3][6]){
                turn_gear(3, next_turn);
            }
            for(int j = 1 ; j >= 0 ; j--){
                if(arr[j+1][6] == arr[j][2]) break;
                else{
                    v.push_back(make_pair(j, next_turn));
                    next_turn = -next_turn;
                }
            }
            
        }
        else if(gear == 3){
            for(int j = 2 ; j >= 0 ; j--){
                if(arr[j+1][6] == arr[j][2]) break;
                else{
                    v.push_back(make_pair(j, next_turn));
                    next_turn = -next_turn;
                }
            }
        }

        turn_gear(gear, turn);

        for(int j = 0 ; j < v.size() ; j++){
            turn_gear(v[j].first, v[j].second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0 ; i < 4 ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < 8 ; j++){
            arr[i][j] = str[j] - '0';
        }
    }

    cin >> k;

    for(int  i = 0 ; i < k ; i++){
        int num1, num2;
        cin >> num1 >> num2;

        number.push_back(num1);
        direction.push_back(num2);
    }

    solve();

    for(int i = 0 ; i < 4 ; i++){
        if(arr[i][0] == 1) {
            ans += pow(2, i);
        }
    }

    cout << ans;

    return 0;
}