/*
BOJ 1992번: 쿼드트리
DATE: 2022-02-14
Divide And Conquer
-
0. 인자로 받은 (x, y)의 숫자로 체크함
1. 해당 범위의 모든 수가 동일 => 숫자 출력
2. 다른 수가 존재한다면 => 4등분해서 재귀
    2-1. 재귀 전 여는 괄호, 끝난 후 닫는 괄호
    2-2. 순서: 왼쪽 위 -> 오른쪽 위 -> 왼쪽 아래 -> 오른쪽 아래
*/
#include <iostream>
#define MAX 64
using namespace std;

int n;
int arr[MAX][MAX];

void solve(int size, int r, int c){
    int check = arr[r][c];
    int dr[4] = {0, 0, size / 2, size / 2};
    int dc[4] = {0, size / 2, 0, size / 2};

    for(int i = r ; i < r + size ; i++){
        for(int j = c ; j < c + size ; j++){
            if(arr[i][j] != check){
                printf("(");
                for(int k = 0 ; k < 4 ; k++) solve(size / 2, r + dr[k], c + dc[k]);
                printf(")");

                return;
            }
        }
    }

    printf("%d", check); // 해당 범위가 0 또는 1로만 이루어진 경우
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    solve(n, 0, 0);

    return 0;
}