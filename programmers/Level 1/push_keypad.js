/*
programmers Level 1: Push keypad
2020 KAKAO Internship
2021-12-21
*/
function solution(board, moves) {
    let answer = 0;
    let stack = [];

    for (let i = 0; i < moves.length; i++) {
        for (let j = 0; j < board.length; j++) {
            if (board[j][moves[i] - 1] > 0) {
                if (stack[stack.length - 1] === board[j][moves[i] - 1]) {
                    answer += 2;
                    stack.pop();
                } else stack.push(board[j][moves[i] - 1]);

                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }

    return answer;
}