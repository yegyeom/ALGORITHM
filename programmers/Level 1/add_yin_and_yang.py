# programmers Level 1: 음양 더하기
# date: 2022-04-14
def solution(absolutes, signs):
    answer = 0
    
    for a, s in zip(absolutes, signs):
        answer += a if s == True else -a
            
    return answer