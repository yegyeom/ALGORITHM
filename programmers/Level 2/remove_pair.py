# programmers Level 2: 짝지어 제거하기
# date: 2022-06-10
def solution(s):
    answer = -1
    list = []
    
    for i in s:
        if len(list) == 0 or list[-1] != i:
            list.append(i)
        elif list[-1] == i:
            list.pop()
    
    if len(list) > 0: answer = 0
    else: answer = 1
    
    return answer