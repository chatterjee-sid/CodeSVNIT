criminal(X) :- american(X), weapon(Y), hostile(Z), sells(X,Y,Z).
hostile(X) :- enemy(X,america).
enemy(nono,america).
owns(nono,allmissiles).
missile(allmissiles).
weapon(X) :- missile(X).
sells(west,X,nono) :- owns(nono,X), missile(X).
american(west).
% ?- criminal(west).
% ?- criminal(X).
