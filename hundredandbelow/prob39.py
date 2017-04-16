# -*- coding: cp1252 -*-
import time

kauan = time.time()
vrt = [0]*2
for p in range(12,1001):
	myoz = 0
	for a in range(1,int(p/(2+2**0.5)+1)):
		oho = float(p**2-2*p*a)/float(2*p-2*a)
		if int(oho) == float(oho):
			myoz += 1
	if myoz>vrt[0]:
		vrt[0],vrt[1]=myoz,p
print vrt [1],time.time()-kauan
