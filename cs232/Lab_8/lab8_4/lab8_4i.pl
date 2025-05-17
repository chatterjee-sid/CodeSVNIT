:- discontiguous
    dancer/1,
    student/1,
    graceful/1.
graceful(X) :- dancer(X).
student(ayesha).
dancer(ayesha).
% student(X), graceful(X).