gcd(X,0,X).
gcd(X,Y,Z):-Y1 is X mod Y,gcd(Y,Y1,Z).