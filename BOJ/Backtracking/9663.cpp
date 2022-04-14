/*
BOJ 9663번: N-Queen
DATE: 2022-04-15
*/
#include <iostream>
#define MAX 15
using namespace std;

int N, ans;
int col[MAX];

bool check(int num){
    for(int i = 0 ; i < num ; i++){
        if(col[i] == col[num]) return false; // 같은 행
        else if(abs(col[num] - col[i]) == num - i) return false; // 대각선
    }

    return true;
}

void nqueen(int num){
    if(num == N){
        ans++;
        return;
    }

    for(int i = 0 ; i < N ; i++){
        col[num] = i;
        if(check(num)) nqueen(num + 1);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;

    nqueen(0);

    cout << ans;

    return 0;
}