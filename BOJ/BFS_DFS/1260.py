# 1260.py
# BOJ 1260번: DFS와 BFS
# DATE: 2022-03-15
import sys
from collections import deque
read = sys.stdin.readline

def dfs(v):
    print(v, end=' ')
    visited[v] = True
    
    for i in graph[v]:
        if not visited[i]:
            dfs(i)

def bfs(n):
    visited[n] = True;
    queue = deque([n])
    
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
    
n, m, v = map(int, read().split())
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)

for _ in range(m):
    a, b = map(int, read().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, n+1):
    graph[i].sort()
    
dfs(v)
visited = [False] * (n+1)
print()
bfs(v)