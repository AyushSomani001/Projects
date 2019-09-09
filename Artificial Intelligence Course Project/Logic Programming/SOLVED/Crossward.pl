word(astante, a,s,t,a,n,t,e).
word(astoria, a,s,t,o,r,i,a).
word(baratto, b,a,r,a,t,t,o).
word(cobalto, c,o,b,a,l,t,o).
word(pistola, p,i,s,t,o,l,a).
word(statale, s,t,a,t,a,l,e).
crossword(V1,V2,V3,H1,H2,H3):-word(V1,A,B,C,D,E,F,G),word(V2,A2,B2,C2,D2,E2,F2,G2),word(V3,A3,B3,C3,D3,E3,F3,G3),word(H1,K,B,L,B2,M,B3,N),word(H2,K2,D,L2,D2,M2,D3,N2),word(H3,K3,F,L3,F2,M3,F3,N3).
crossword1(V1,V2,V3,H1,H2,H3):-word1(V1,A,B,C,D,E,F,G),word1(V2,A2,B2,C2,D2,E2,F2,G2),word1(V3,A3,B3,C3,D3,E3,F3,G3),word1(H1,K,B,L,B2,M,B3,N),word1(H2,K2,D,L2,D2,M2,D3,N2),word1(H3,K3,F,L3,F2,M3,F3,N3).