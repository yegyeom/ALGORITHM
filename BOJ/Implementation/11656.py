# 11656.py
# BOJ 11656: 접미사 배열
# DATE: 2022-03-15
import sys
read = sys.stdin.readline

s = read().strip()
s_list = []

for i in range(len(s)):
    s_list.append(s[i:])

for i in sorted(s_list):
    print(i)