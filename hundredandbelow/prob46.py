# -*- coding: cp1252 -*-
import time

aika = time.time()
#hidastuu oddprimen vuoksi, jos joukko alkulukuja laskettaisiin heti alkuun, vältyttäisiin toistoilta
def oddprime(luumu):
	k = 1
	if luumu%2 == 0: k = 0
	for a in range(3,int(luumu*0.5+1),2):
		if luumu%a == 0: k = 0; break
	return k

eitulosta,roadrunner = 1,9
while eitulosta:
	if oddprime(roadrunner)==1: roadrunner+=2
	else:
		kaa = 1
		for ii in range(1,int((roadrunner)**0.5+1)):
			ahaa = roadrunner-2*(ii**2)
			if ahaa < 3: break
			if oddprime(ahaa)==1: kaa = 0; break
		if kaa == 1:
			eitulosta = 0
			break
		roadrunner += 2
print roadrunner,time.time()-aika
