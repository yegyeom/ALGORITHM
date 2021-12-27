/*
programmers Level 2: 가장 큰 수
2021-12-27
*/
function solution(numbers) {
    let answer = numbers.sort((a, b) => `${b}${a}` - `${a}${b}`).join('');
    answer = answer[0] === "0" ? "0" : answer;

    return answer;
}