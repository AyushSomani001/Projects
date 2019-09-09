male(prajwal).
female(survi).
gender(X):-male(X),write('You are male').
gender(X):-female(X),write('You are female').
alter:-write('What is your name'),read(X),gender(X).