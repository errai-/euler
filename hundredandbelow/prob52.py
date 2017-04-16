# -*- coding: cp1252 -*-
import time

aapinen = time.time()
def paaryna(numero,kerroin=2):
	paluu,nemero = 1,str(numero)
	numero2 = str(kerroin*numero)
	for doo in nemero:
		if doo not in numero2:
			paluu = 0; break
	if paluu == 1 and kerroin != 6:
		paluu = paaryna(numero,kerroin+1)
	return paluu
		 

i,ei = 11,1
while ei:
	koo = 0
	for daa in range(len(str(i))):
		if (str(i)).count(str(i)[daa])!=1:
			koo = 1
	if koo == 0:
		if paaryna(i) == 1: break
	i += 1
print i,time.time()-aapinen
