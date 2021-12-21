/*
programmers Level 1: 숫자 문자열과 영단어
2021 카카오 채용연계형 인턴십
2021-12-21
*/
function solution(s) {
    const arr = [/zero/gi, /one/gi, /two/gi, /three/gi, /four/gi, /five/gi, /six/gi, /seven/gi, /eight/gi, /nine/gi];

    for (let i = 0; i < arr.length; i++) s = s.replace(arr[i], i)

    return parseInt(s);
}