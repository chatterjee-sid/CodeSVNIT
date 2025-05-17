:- discontiguous
    wellKnown/1,
    studPrez/1.
wellKnown(X) :- studPrez(X).
studPrez(me) :- false.
% \+ wellKnown(me)