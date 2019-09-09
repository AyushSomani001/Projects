length1([],0).
length1([X|T],N):-length1(T,N1),N is N1+1.

empty([]).
empty([Head|Tail]):-length1(Head,0),empty(Tail).

multrow(D1,D2,X3,R):-empty(D1),empty(D2),X3=R.
multrow([Head|Tail],[[F1|F2]|F3],X3,R):-R1 is Head*F1+R,multrow(Tail,F3,X3,R1).

same1([],[]).
same1([X1|T1],[X2|T2]):-X1=X2,same1(T1,T2).

remove([],[]).
remove([[F1|F2]|F3],[Head|Tail]):-same1(F2,Head),remove(F3,Tail).


mult(X,M,L):-empty(M),empty(L).
mult(X,[[F1|F2]|F3],[X3|Y3]):-multrow(X,[[F1|F2]|F3],X3,0),remove([[F1|F2]|F3],Z1),mult(X,Z1,Y3).


multiplymat([],S,[]).
multiplymat([X|Y],S,[X5|Y5]):-mult(X,S,X5),multiplymat(Y,S,Y5).



