% Load the Queensland road network.
load("queenslandRoutes","places","routes")
% Specify states, links, and weights for a navGraph object.
states = places.utm;               % UTM coordinates of cities
names = places.name;               % Names of cities
links = [routes.start routes.end]; % Adjacent cities
weights = routes.time;             % Travel time between adjacent cities
% Create a navGraph object.
graphObj = navGraph(states,links,Weight=weights, ...
                    Name=names);
% Create a graph-based A* path planner.
planner = plannerAStar(graphObj);
% Create a deep copy of the plannerAStar object.
planner2 = copy(planner)
% Specify a heuristic function returns an estimated time to reach the goal.
planner.HeuristicCostFcn = @(state1,state2) ...
    sum(abs(state1-state2),2)/100;
% Define the start and goal cities.
start = "Hughenden";
goal = "Brisbane";
% Find the shortest path using the graph-based A* algorithm.
[pathOutput,solutionInfo] = plan(planner,start,goal);
% Visualize the results.
h = show(graphObj);
set(h,XData=graphObj.States.StateVector(:,1), ...
      YData=graphObj.States.StateVector(:,2))
pathStateIDs = solutionInfo.PathStateIDs;
highlight(h,pathStateIDs,EdgeColor="#EDB120",LineWidth=4)
highlight(h,pathStateIDs(1),NodeColor="#77AC30",MarkerSize=5)
highlight(h,pathStateIDs(end),NodeColor="#D95319",MarkerSize=5)