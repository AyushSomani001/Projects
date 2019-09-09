length1([],0).
length1([X|L],N):-length1(L,N1),N is N1+1.