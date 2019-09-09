same1([],[]).
same1([Head|Tail],[Head1|Tail1]):-Head=Head1,same1(Tail,Tail1).

different(X,Y):-X>Y.
different(X,Y):-Y>X.

check(A,[],R,N).
check(A,[BH|BT],R,N):-BH>0,N1 is N+1,BH<N1,R1 is A+R,R3 is A-R,different(BH,R1),different(BH,R3),different(BH,A),R2 is R+1,check(A,BT,R2,N).
solution([],N).
solution([Head|Tail],N):-Head>0,N1 is N+1,Head<N1,check(Head,Tail,1,N),solution(Tail,N).


fill1(4,[4,3,2,1]).
fill1(N,[Head|Tail]):-Head=N,N1 is N-1,fill1(N1,Tail).


answer(R,Z,N):-permutation(R,Q),solution(Q,N),same1(Z,Q).

nqueen(0,[]).
nqueen(N,Z):-fill1(N,R),answer(R,Z,N).