:- discontiguous
    class1/1,
    class2/1,
    wealthy/1,
    passenger/1.
class1(X) :- passenger(X), \+ class2(X).
class2(X) :- passenger(X), \+ wealthy(X).
wealthy(someone).
passenger(someother).
% passenger(X), class2(X).