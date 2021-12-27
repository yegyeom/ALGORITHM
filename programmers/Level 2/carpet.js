/*
programmers Level 2: 카펫
2021-12-27
*/
function solution(brown, yellow) {
    let answer = [];
    let h = 3, w;

    while (1) {
        w = Math.floor((brown + yellow) / h);

        if ((h - 2) * (w - 2) == yellow) break;
        h++;
    }

    answer.push(w, h);

    return answer;
}