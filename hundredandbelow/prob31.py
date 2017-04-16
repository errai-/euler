# -*- coding: cp1252 -*-
import time

saa,kaasua,kaikki = time.time(),[200,100,50,20,10,5,2,1],200

def lapio(sisaan,a,lukum=0):
	d = sisaan/kaasua[a]
	for baa in range(0,d+1):
		if baa*kaasua[a]==sisaan: lukum += 1
		else:
			suu = sisaan - baa*kaasua[a]
			if a < 7: lukum = lapio(suu,a+1,lukum)
			else: continue
	return lukum

luku = 0
for i in range(len(kaasua)):
	d = kaikki/kaasua[i]
	for qaa in range(1,d+1):
		if qaa*kaasua[i]==kaikki: luku+=1
		else:
			suu = kaikki - qaa*kaasua[i]
			if i < 7: luku += lapio(suu,i+1)
			else: continue
print luku,time.time()-saa
