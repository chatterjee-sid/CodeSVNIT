from typing import *
from collections import deque

def bfs(start: int, state: List[int]) -> None:
    while search:
        x = search.popleft()
        if visit[x]:
            continue
        visit[x] = True
        for i in range(4):
            if visit[i]:
                continue
            if rooms[x][i]:
                search.append(i)
        if state[x]:
            print(x+1,'S')
            state[x] = 0
        else:
            print(x+1,'N')
        if not search:
            return
        diff = search[0] - x
        if diff==1:
            print(x+1,'R')
        elif diff==-1:
            print(x+1,'L')
        elif diff==-2:
            print(x+1,'U')
        elif diff==2:
            print(x+1,'D')
        elif diff==3:
            print(x+1,'R')
            print(x+2,'D')
        elif diff==-3:
            print(x+1,'L')
            print(x,'U')

def dfs(start: int, state: List[int]) -> None:
    while search:
        x = search.pop()
        if visit[x]:
            continue
        visit[x] = True
        for i in range(4):
            if visit[i]:
                continue
            if rooms[x][i]:
                search.append(i)
        if state[x]:
            print(x+1,'S')
            state[x] = 0
        else:
            print(x+1,'N')
        if not search:
            return
        diff = search[-1] - x
        if diff==1:
            print(x+1,'R')
        elif diff==-1:
            print(x+1,'L')
        elif diff==-2:
            print(x+1,'U')
        elif diff==2:
            print(x+1,'D')
        elif diff==3:
            print(x+1,'R')
            print(x+2,'D')
        elif diff==-3:
            print(x+1,'L')
            print(x,'U')

rooms = [
    [0,1,1,0],
    [1,0,0,1],
    [1,0,0,1],
    [0,1,1,0]
]
start = int(input())
state = list(map(int,input().split()))
method = input()
visit = [False, False, False, False]
search = deque([start-1])
if method=='bfs':
    bfs(start,state)
else:
    dfs(start,state)

