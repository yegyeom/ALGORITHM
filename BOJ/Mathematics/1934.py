# 1934.py
# BOJ 1934번: 최소공배수
# DATE: 2022-03-18
import sys
read = sys.stdin.readline

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

t = int(read())

for _ in range(t):
    a, b = map(int, read().split())
    print(a * b // gcd(a, b))