colours([red, blue, green, yellow]).
regions([1, 2, 3, 4, 5, 6]).
adj([(1,2),(1,3),(1,4),(1,6),
      (2,3),(2,5),
      (3,4),(3,5),
      (4,5),(5,6)]).
adjacent(X,Y) :- adj(Edges), (member((X,Y),Edges); member((Y,X),Edges)).
% this rules allows symmetry in adjacencies.

colouring(Region2Colour) :-
    colours(Colors),
    regions(Regions),
    assign(Regions, Colors, [], Region2Colour).
% this procedure is our principal procedure for query 

assign([], _, Region2Colour, Region2Colour). % base case, for stopping when all regions have been assigned a colour.
% the assign/4 procedure is used to assign a colour to each region one by one. It tries all possible combinations of colours.
assign([Region | Remaining], Colors, Partial, Region2Colour) :-
    member(Color, Colors),
    valid_color(Region, Color, Partial),
    assign(Remaining, Colors, [(Region-Color) | Partial], Region2Colour).

% This procedure is to make sure that no 2 djacent regions share the same colour.
valid_color(Region, Color, Partial) :-
    \+ (adjacent(Region, Adj), member(Adj-AdjColor, Partial), AdjColor == Color).

% ?- colouring(RegionColour).