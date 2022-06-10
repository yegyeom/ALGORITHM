# programmers Level 3: 섬 연결하기
# date: 2022-06-11
parent = []

def getParent(x):
    if x == parent[x]: 
        return x
    parent[x] = getParent(parent[x])
    return parent[x]

def findParent(a, b):
    a = getParent(a)
    b = getParent(b)
    
    if a == b: 
        return 1
    else:
        return 0
    
def unionParent(a, b):
    a = getParent(a)
    b = getParent(b)
    
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

def solution(n, costs):
    answer = 0
    
    for i in range(n + 1):
        parent.append(i)
    
    for i in range(len(costs)):
        costs[i][0], costs[i][1], costs[i][2] = costs[i][2], costs[i][0], costs[i][1]
    
    costs.sort()
    
    for i in costs:
        if not findParent(i[1], i[2]):
            unionParent(i[1], i[2])
            answer += i[0]
    
    return answer