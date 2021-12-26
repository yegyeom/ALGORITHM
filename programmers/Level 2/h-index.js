/*
programmers Level 2: H-index
2021-12-26
*/
function solution(citations) {
    let answer = 0;
    let num = citations.length;

    citations.sort((a, b) => {
        return a - b
    });

    for (let i = num; i >= 0; i--) {
        let index = citations.findIndex(v => v >= i);
        index = index === -1 ? num : index;

        if (num - index >= i) {
            answer = i
            break;
        }
    }

    return answer;
}