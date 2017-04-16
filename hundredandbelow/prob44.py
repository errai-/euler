# -*- coding: cp1252 -*-
import time

aika = time.time()
def ispentagonal(luu,i):
	k = 0
	doo = (1+(1+24*luu)**0.5)/3
	if int(doo) == doo:
		k = 1
	return k
pentagonals = []
for i in range(1,2600):
	pentagonals.append(0.5*(3*(i**2)-i))
q = 0
for aa in range(1,len(pentagonals)):
	for bee in range(aa+1,len(pentagonals)):
		gaf = pentagonals[bee] - pentagonals[aa]
		if ispentagonal(gaf,0)==1:
			daf = pentagonals[bee]+pentagonals[aa]
			s = ispentagonal(daf,1)
			if s == 1: q,koo = 1,gaf; break
	if q == 1: break
print koo, time.time()-aika
