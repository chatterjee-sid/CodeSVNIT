# Dijkstra might help
from typing import *
from collections import deque

def bfs(start: int) -> None:
    parents = [[-1,float('inf')] for i in range(6)]
    parents[start][1] = 0
    while search:
        x = search.popleft()
        if x==5:
            room = [x]
            while parents[x][0]>-1:
                x = parents[x][0]
                room.append(x)
            print('-'.join(map(str,room[::-1])))
            return
        for i in range(6):
            if route[x][i]:
                if parents[i][1]>parents[x][1]+1:
                    parents[i] = [x,parents[x][1]+1]
                    search.append(i)

def dfs(start: int) -> None:
    parents = [[-1,float('inf')] for i in range(6)]
    parents[start][1] = 0
    while search:
        x = search.pop()
        if x==5:
            room = [x]
            while parents[x][0]>-1:
                x = parents[x][0]
                room.append(x)
            print('-'.join(map(str,room[::-1])))
            return
        for i in range(6):
            if route[x][i]:
                if parents[i][1]>parents[x][1]+1:
                    parents[i] = [x,parents[x][1]+1]
                    search.append(i)

route = [
    [0,0,0,0,1,0],
    [0,0,0,1,0,1],
    [0,0,0,1,0,0],
    [0,1,1,0,1,0],
    [1,0,0,1,0,1]
]

start,method = input().split()
start = int(start)
search = deque([start])
visit = [False for _ in range(6)]
if method=="bfs":
    bfs(start)
else:
    dfs(start)