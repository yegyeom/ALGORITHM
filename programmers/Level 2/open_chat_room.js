/*
programmers Level 2: Open chat room
2019 KAKAO BLIND RECRUITMENT
2021-12-21
*/
function solution(record) {
    const answer = [];
    const user = {};

    record.forEach((item) => {
        const [state, uid, nick] = item.split(' ');

        if (state !== 'Leave') user[uid] = nick
    })

    record.forEach((item) => {
        const [state, uid, nick] = item.split(' ');

        if (state === 'Enter') answer.push(`${user[uid]}님이 들어왔습니다.`)
        else if (state === 'Leave') answer.push(`${user[uid]}님이 나갔습니다.`)
    })

    return answer;
}