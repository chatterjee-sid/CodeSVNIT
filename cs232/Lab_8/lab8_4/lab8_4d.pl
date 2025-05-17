:- discontiguous
    gsec/1,
    vp/1,
    treasurer/1.
gsec(rajat) :- vp(asha).
treasurer(bharati) :- vp(asha).
gsec(rajat) :- false.
% \+ vp(asha).