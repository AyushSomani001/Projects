lets(mary,jill).
lets(jill,ram).
god(X,Y):-lets(X,Y),write('YES ITS AVAILABLE').
info:-write('Please enter the information '),read(X),write('  '),read(Y),god(X,Y).
