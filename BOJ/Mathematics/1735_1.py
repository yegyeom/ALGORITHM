# 1735_1.py (gcd 함수 구현)
# BOJ 1735: 분수 합
# DATE: 2022-03-16
import sys
read = sys.stdin.readline

def gcd(n, m):
    return n if m == 0 else gcd(m, n % m)
    
a, b = map(int, read().split())
c, d = map(int, read().split())

n = a * d + b * c
m = b * d

div = gcd(n, m)

print(n // div, m // div)