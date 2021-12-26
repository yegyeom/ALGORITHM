/*
programmers Level 1: 신규 아이디 추천
2021 KAKAO BLIND RECRUITMENT
2021-12-26
*/
function solution(new_id) {
    // 1
    new_id = new_id.toLowerCase();

    // 2
    new_id = new_id.replace(/[^\w-.]/g, '');

    // 3
    new_id = new_id.replace(/[.]+/g, '.');

    // 4
    new_id = new_id[0] === "." ? new_id.slice(1) : new_id;
    new_id = new_id[new_id.length - 1] === "." ? new_id.slice(0, new_id.length - 1) : new_id;

    // 5
    new_id = new_id.length === 0 ? "a" : new_id;

    // 6
    new_id = new_id.slice(0, 15);
    new_id = new_id[14] === '.' ? new_id.slice(0, 14) : new_id;

    // 7
    if (new_id.length < 3) {
        let tmp = new_id[new_id.length - 1];
        while (new_id.length < 3) new_id += tmp;
    }

    return new_id;
}