# 1735_2.py (math 라이브러리의 gcd 함수 사용)
# BOJ 1735: 분수 합
# DATE: 2022-03-16
import sys
import math
read = sys.stdin.readline
    
a, b = map(int, read().split())
c, d = map(int, read().split())

n = a * d + b * c
m = b * d

div = math.gcd(n, m)

print(n // div, m // div)