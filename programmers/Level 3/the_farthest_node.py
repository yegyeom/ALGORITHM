# programmers Level 3: 가장 먼 노드
# date: 2022-04-15
def solution(n, edge):
    graph = [[] for _ in range(n+1)]
    visited = [False] * (n + 1)
    d = [[]] * (n + 1)

    for a, b in edge:
        graph[a].append(b)
        graph[b].append(a)
    
    queue = []
    queue.append(1)
    visited[1] = True
    d[1] = 0
    
    while queue:
        cur = queue.pop(0)
        
        for i in graph[cur]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
                d[i] = d[cur] + 1
                
    d = d[1:]
    answer = d.count(max(d))
    
    return answer