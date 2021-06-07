//programmers Level 3 : Lock and Key
//2020 KAKAO BLIND RECRUITMENT
//2021-05-29
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool sum(int x, int y, vector<vector<int>> key, vector<vector<int>> board){
    int M = key.size();
    int bs = board.size();
    
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < M ; j++){
            board[x + i][y + j] += key[i][j];
        }
    }
    
    for(int i = M - 1 ; i < bs - M + 1; i++){
        for(int j = M - 1 ; j < bs - M + 1 ; j++){
            if(board[i][j] != 1)
                return false;
        }
    }
    
    return true;
}

vector<vector<int>> rotate(vector<vector<int>> key){
    int M = key.size();
    vector<vector<int>> tmp(M, vector<int>(M, 0));
    
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < M ; j++){
            tmp[i][j] = key[M - j - 1][i];
        }
    }
    
    key = tmp;
    return key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int M = key.size();
    int N = lock.size();
    int bs = lock.size() + (key.size() - 1)*2;
    vector<vector<int>> board(bs, vector<int>(bs, 0));
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            board[i + M - 1][j + M - 1] = lock[i][j];
        }
    }
    
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < M+N-1 ; j++){
            for(int k = 0 ; k < M+N-1 ; k++){
                if(sum(j, k , key, board)){
                    answer = true;
                    return answer;
                }
            }
        }
        key = rotate(key);
    }
    
    return answer;
}

int main(){
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    if(solution(key, lock)) cout << "true\n";
    else cout << "false\n";

    return 0;
}