# programmers Level 1: 소수 만들기
# date: 2022-04-14
from itertools import combinations
from math import sqrt

def isPrime(num):
    for i in range(2, int(sqrt(num) + 1)):
        if num % i == 0: return False
    
    return True
    
def solution(nums):
    answer = 0
    
    nums = sorted(nums)
    
    for i in combinations(nums, 3):
        if isPrime(sum(i)):
            answer += 1
            
    return answer