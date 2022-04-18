# programmers Level 1: 두 개 뽑아서 더하기
# date: 2022-04-14
import itertools

def solution(numbers):
    answer = []

    for i in itertools.combinations(numbers, 2):
        answer.append(i[0] + i[1])

    answer = sorted(set(answer))

    return answer