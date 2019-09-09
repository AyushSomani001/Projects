factorial(0,1).
factorial(1,1).
factorial(X,N):-factorial(X1,N1),X is X1+1,N is N1*X.