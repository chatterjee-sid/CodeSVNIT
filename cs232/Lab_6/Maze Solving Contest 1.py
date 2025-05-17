from heapq import *
from collections import deque
from random import randint

def maze_valid(maze, state):
    '''
    A function to check whether it is possible to arrive at the particular
    state at all.
    '''
    x,y = state
    if 0 <= x < 5 and 0 <= y < 5 and maze[x][y]!=1:
        return True
    return False

def bfs(maze, state, goals):
    if not goals: #if no rewards are left, we quit
        return 1
    visited = {state} #We keep track of already visited nodes here
    queue = deque([(state,[])]) #Most commonly used data structure in this algorithm
    while queue:
        thisstate,path = queue.popleft()
        if thisstate in goals:
            goals.remove(thisstate) #This reward has been obtained
            # print(path)
            return bfs(maze, thisstate, goals) + len(path) # having found a reward, we start afresh for the rest of the rewards
        path.append(thisstate)
        r,c = thisstate
        for i,j in [(0,1),(1,0),(0,-1),(-1,0)]:
            newstate = (r+i,c+j)
            if maze_valid(maze, newstate) and newstate not in visited:
                visited.add(newstate)
                queue.append((newstate,path))
    return float('inf')

def dfs(maze, state, goals):
    if not goals: #if no rewards are left, we quit
        return 1
    visited = {state} #We keep track of already visited nodes here
    stack = deque([(state,[])]) #Most commonly used data structure in this algorithm
    while stack:
        thisstate,path = stack.pop()
        if thisstate in goals:
            goals.remove(thisstate) #This reward has been obtained
            # print(path)
            return dfs(maze, thisstate, goals) + len(path) # having found a reward, we start afresh for the rest of the rewards
        path.append(thisstate)
        r,c = thisstate
        for i,j in [(0,1),(1,0),(0,-1),(-1,0)]:
            newstate = (r+i,c+j)
            if maze_valid(maze, newstate) and newstate not in visited:
                visited.add(newstate)
                stack.append((newstate,path))
    return float('inf')

def ucs(maze, state, goals):
    if not goals: #if no rewards are left, we quit
        return 1
    pq = [] # a priority queue / heap
    g_cost = {state:0} # This works as our visited in other functions, with extra steps
    heappush(pq,(0,state,[])) #Most commonly used data structure in this algorithm
    while pq:
        _,thisstate,path = heappop(pq)
        if thisstate in goals:
            goals.remove(thisstate) #This reward has been obtained
            # print(path)
            return ucs(maze, thisstate, goals) + len(path) # having found a reward, we start afresh for the rest of the rewards
        path.append(thisstate)
        r,c = thisstate
        for i,j in [(0,1),(1,0),(0,-1),(-1,0)]:
            newstate = (r+i,c+j)
            if maze_valid(maze, newstate):
                n_cost = g_cost[thisstate] + 1
                if g_cost.get(newstate,float('inf')) > n_cost:
                    g_cost[newstate] = n_cost
                    heappush(pq,(n_cost,newstate,path))
    return float('inf')

def gbfs(maze, state, goals):
    if not goals: #if no rewards are left, we quit
        return 1
    pq = [] # a priority queue / heap
    visited = {state} #We keep track of already visited nodes here
    heappush(pq,(hfunction(state,goals),state,[])) #Most commonly used data structure in this algorithm
    while pq:
        _,thisstate,path = heappop(pq)
        if thisstate in goals:
            goals.remove(thisstate) #This reward has been obtained
            # print(path)
            return gbfs(maze, thisstate, goals) + len(path) # having found a reward, we start afresh for the rest of the rewards
        path.append(thisstate)
        r,c = thisstate
        for i,j in [(0,1),(1,0),(0,-1),(-1,0)]:
            newstate = (r+i,c+j)
            if maze_valid(maze, newstate) and not newstate in visited:
                visited.add(newstate)
                heappush(pq,(hfunction(state,goals),newstate,path))
    return float('inf')

def astar(maze, state, goals):
    if not goals: #if no rewards are left, we quit
        return 1
    pq = [] # a priority queue / heap
    g_cost = {state:0} # This works as our visited in other functions, with extra steps
    heappush(pq,(hfunction(state,goals),state,[])) #Most commonly used data structure in this algorithm
    while pq:
        _,thisstate,path = heappop(pq)
        if thisstate in goals:
            goals.remove(thisstate) #This reward has been obtained
            # print(path)
            return astar(maze, thisstate, goals) + len(path) # having found a reward, we start afresh for the rest of the rewards
        path.append(thisstate)
        r,c = thisstate
        for i,j in [(0,1),(1,0),(0,-1),(-1,0)]:
            newstate = (r+i,c+j)
            if maze_valid(maze, newstate):
                n_cost = g_cost[thisstate] + 1
                if g_cost.get(newstate,float('inf')) > n_cost:
                    g_cost[newstate] = n_cost
                    heappush(pq,(n_cost + hfunction(state,goals),newstate,path))
    return float('inf')

def hfunction(state,goals):
    return sum(abs(state[0]-goal[0]) + abs(state[1]-goal[1]) for goal in goals)

def perform(maze, start, approach, goals):
    pathlen = float('inf')
    if approach==0:
        pathlen = bfs(maze, start, goals.copy())
    elif approach==1:
        pathlen = dfs(maze, start, goals.copy())
    elif approach==2:
        pathlen = ucs(maze, start, goals.copy())
    elif approach==3:
        pathlen = gbfs(maze, start, goals.copy())
    else:
        pathlen = astar(maze, start, goals.copy())
    return pathlen

if __name__=="__main__":
    maze = [
        [2,0,0,0,1],
        [0,1,0,0,3],
        [0,3,0,1,1],
        [0,1,0,0,1],
        [3,0,0,2,3]
    ]
    startA = (0,0)
    startB = (4,3)
    goals = []
    for i in range(5):
        for j in range(5):
            if maze[i][j] == 3:
                goals.append((i,j))
    with open("out_advsearch.txt", "w") as f:
        awins, bwins = 0, 0
        for i in range(10):
            approachA = randint(0, 4)
            approachB = randint(0, 4)
            a = perform(maze, startA, approachA, goals.copy())
            b = perform(maze, startB, approachB, goals.copy())

            if a < b:
                f.write(f"Winner of round {i+1} is A.\n")
                awins += 1
            elif b < a:
                f.write(f"Winner of round {i+1} is B.\n")
                bwins += 1
            else:
                f.write(f"Round {i+1} ends in a draw.\n")

            f.write(f"A made {a} moves, while B made {b} moves in round {i+1}.\n")

        if awins > bwins:
            f.write(f"A is the overall winner with {awins} wins and {bwins} losses.\n")
        elif bwins > awins:
            f.write(f"B is the overall winner with {bwins} wins and {awins} losses.\n")
        else:
            f.write(f"The overall match ends in a draw with both having {awins} wins.\n")
