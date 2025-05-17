% RULES
father(X,Y) :- parent(X,Y), male(X).
mother(X,Y) :- parent(X,Y), female(X).
sibling(X,Y) :- father(Z,X), father(Z,Y), X \= Y.
% can use mother instead of father, parent was not used to avoid repetition of results
grandparent(X,Y) :- parent(X,Z), parent(Z,Y).
grandmother(X,Y) :- grandparent(X,Y), female(X).
grandfather(X,Y) :- grandparent(X,Y), male(X).
cousin(X,Y) :- father(A,X), father(B,Y), grandfather(C,X), grandfather(C,Y), A \= B.
% can use mother instead of father, and/or grandmother instead of grandfather, parent/grandparent was not used to avoid repetition of results
uncle(X,Y) :- father(X,B), cousin(B,Y).
uncle(X,Y) :- parent(B,Y), sibling(X,B), male(X).
aunt(X,Y) :- mother(X,B), cousin(B,Y).
aunt(X,Y) :- parent(B,Y), sibling(X,B), female(X).

% FACTS
male(bamacharan).
male(partha).
male(siddhartha).
male(swapan).
male(arghya).
male(alekhya).
female(alpana).
female(kalpana).
female(sharmistha).
female(aditi).
parent(bamacharan,partha).
parent(alpana,partha).
parent(swapan,sharmistha).
parent(swapan,aditi).
parent(kalpana,sharmistha).
parent(kalpana,aditi).
parent(partha,siddhartha).
parent(sharmistha,siddhartha).
parent(arghya,alekhya).
parent(aditi,alekhya).