newborn(mary).
father(adam,mary).
parent(X,Y):-father(X,Y).
parent(X,Y):-mother(X,Y).
proud(X):-newborn(Y),parent(X,Y).