# programmers Level 1: 완주하지 못한 선수
# date: 2022-04-15
def solution(participant, completion):
    answer = ''
    dic = {}
    
    for x in participant:
        dic[x] = dic.get(x, 0) + 1
    
    for x in completion:
        dic[x] -= 1
    
    for k, v in dic.items():
        if v == 1:
            answer = k
            break
            
    return answer