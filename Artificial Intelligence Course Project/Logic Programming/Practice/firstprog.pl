
implies(x,y).
implies(y,z).
implies(z,q).
implies(a,b).
impliesind(Param1,Param2):-implies(Param1,Param2).
impliesind(Param1,Param2):-implies(Param1,Param3),impliesind(Param3,Param2).