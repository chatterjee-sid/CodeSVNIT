from heapq import *
def maze_valid(state, maze): #check if agent can move to this state at any point
    return state[0]>=0 and state[1]>=0 and state[0]<len(maze) and state[1]<len(maze[0]) and maze[state[0]][state[1]]!=1

def astar(maze, start, goal):
    pq = [] #acts as priority queue
    g_cost = {start:0} #stores already computed costs g(n)
    heappush(pq,(heuristic(start,goal),start,[start])) #priority, position, path - priority defined by f(n) = g(n) + h(n)
    while pq: #works till all valid best paths are checked
        _,state,path = heappop(pq)
        if state==goal:
            return path #goal reached, hence exiting
        for i,j in [(0,1),(1,0),(0,-1),(-1,0)]: #checking neighbour nodes
            n_state = (state[0]+i,state[1]+j)
            if maze_valid(n_state,maze): #checking their validity
                n_cost = g_cost[state] + 1 #updating cost covered till now
                if g_cost.get(n_state,float('inf')) > n_cost: #reducing cost of state if we discover a cheaper route to here
                    g_cost[n_state] = n_cost
                    e_cost = n_cost + heuristic(n_state, goal) #re-evaluating estimated cost of this state
                    heappush(pq,(e_cost,n_state,path+[n_state])) #inserting further optimised route into pq
    return None #in the case it is not possible to reach goal at all (in case of obstacle blockage, for example)

def heuristic(start, goal):
    return abs(start[0]-goal[0]) + abs(start[1]-goal[1]) #manhattan distance heuristic

#This program assumes that our goal state is any of the goals possible
if __name__=="__main__":
    maze = [
        [2,0,0,0,1],
        [0,1,0,0,3],
        [0,3,0,1,1],
        [0,1,0,0,1],
        [3,0,0,0,3]
    ]
    start = ()
    goals = []
    for i in range(5):
        for j in range(5):
            if maze[i][j]==2:
                start = (i,j)
            elif maze[i][j]==3:
                goals.append((i,j))
    path = []
    for i in goals: #check astar based path for each goal
        curpath = astar(maze,start,i)
        if not path:
            if curpath:
                path = curpath.copy()
        else:
            if curpath and len(path)>len(curpath): #we want a path with least possible length
                path = curpath.copy()
    with open("out_astar.txt","w") as op:
        op.write(f"{len(path)-1} Moves\n")
        for i,j in path:
            op.write(f"({i},{j}) ")