from typing import *
from heapq import *
def maze_valid(state: List[int], maze: List[List[int]]) -> bool:
    return state[0]>=0 and state[1]>=0 and state[0]<len(maze) and state[1]<len(maze[0]) and maze[state[0]][state[1]]==0
def dls(maze: List[List[int]], state: List[int], goal: List[int], limit: int, path: List[List[int]], depth: int) -> Tuple[List[List[int]], bool]:
    if state==goal: #no need to check further if goal is reached
        return path,False
    if depth>=limit: #we can't further explore node in dls if depth limit is reached
        return None,True #None because we reached this point meaning we did not find a proper route, so route does not exist in this direction, True means search ended due to depth limit reached, implemented for idfs
    for i,j in [(0,1),(1,0),(0,-1),(-1,0)]: #to look around in adjacent directions
        ns = [state[0]+i,state[1]+j]
        if maze_valid(ns,maze): #checks if the current state is a valid stae or not
            result,ex = dls(maze,ns,goal,limit,path+[ns],depth+1) #using recursion to explore neighbour nodes after increasing depth
            if result: #only if a valid route is found, won't execute if result==None
                return result,False #maybe ex would've worked but I don't want to take infinite loop risk (ex is my loop breaker in idfs)
    return None,False #if none of the neighbour nodes lead to a proper route
    # return[1]==False means goal was found or obstacles blocked, result[1]==True means depth limit reached

def idfs(maze: List[List[int]], start: List[int], goal: List[int]) -> List[List[int]]: #disadvantage of dls is that we cannot check if the goal node exists outside depth limit
    limit = 3 #we start with limit 3, as specified in question
    while True:
        result,ex = dls(maze,start,goal,limit,[],0) #recursively calling dls
        if not ex: #this means either goal was found, or obstacles blocked, which means goal will never be reached no matter how much we increase the loop
            return result
        limit += 1 #if depth limit was reached, simply increase limit by 1

def astar(maze: List[List[int]], start: List[int], goal: List[int]):
    pq = []
    heappush(pq,(0,start,[])) #priority, position, path