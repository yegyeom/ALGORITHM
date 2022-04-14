/*
BOJ 7682번: 틱택토
DATE: 2022-04-15
*/
#include <iostream>
using namespace std;

char arr[3][3];

bool checkWin(string str, char win){
    // 가로 
    for(int i = 0 ; i < 3 ; i++){
        if(arr[i][0] == win && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) return true;
    }

    // 세로
    for(int i = 0 ; i < 3 ; i++){
        if(arr[0][i] == win && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) return true;
    }

    // 대각선
    if(arr[0][0] == win && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) return true;
    if(arr[0][2] == win && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) return true;

    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;

    while(1){
        cin >> str;

        if(str == "end") break;

        int X = 0, O = 0;

        for(int i = 0 ; i < 9 ; i++) {
            if(str[i] == 'X') X++;
            else if(str[i] == 'O') O++;
            arr[i / 3][i % 3] = str[i];
        }

        if(X == O + 1 && checkWin(str, 'X') && !checkWin(str, 'O')) { // X 승
            cout << "valid\n";
        }
        else if(X == O && checkWin(str, 'O') && !checkWin(str, 'X')){ // O 승
            cout << "valid\n";
        }
        else if(X == 5 && O == 4 && !checkWin(str, 'X') && !checkWin(str, 'O')){ // 비김
            cout << "valid\n";
        }
        else cout << "invalid\n";
    }

    return 0;
}