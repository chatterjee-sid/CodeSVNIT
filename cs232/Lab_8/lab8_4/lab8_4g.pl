:- discontiguous
    engineer/1,
    contractor/1,
    dependable/1.
dependable(X) :- \+ contractor(X).
contractor(someone).
engineer(someone).
% \+ dependable(X), engineer(X).