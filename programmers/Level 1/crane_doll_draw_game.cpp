//programmers Level 1 : Crane doll draw game
//2019 KAKAO Winter Internship
//2021-05-07
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> v;
    
    for(int i = 0 ; i < moves.size() ; i++){
        for(int j = 0 ; j < board.size() ; j++){
            if(board[j][moves[i] - 1] > 0){
                v.push_back(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                break;
            }
        }    
    }
    
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] == v[i - 1]){
            answer += 2;
            v.erase(v.begin() + (i - 1) , v.begin() + (i + 1));
            i-=2;
        }
    }
    
    return answer;
}

int main(){
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};

    int num = solution(board, moves);
    cout << num;

    return 0;
}