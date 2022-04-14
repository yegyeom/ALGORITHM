# programmers Level 3: 네트워크
# date: 2022-04-15
def solution(n, computers):
    answer = 0
    visited = [False] * n
    
    def dfs(i, n):
        visited[i] = True;

        for j in range(n):
            if(computers[i][j] and visited[j] == False):
                dfs(j, n)
            
    for i in range(n):
        if not visited[i]:
            answer += 1;
            dfs(i, n)
    
    return answer