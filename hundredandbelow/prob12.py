# -*- coding: cp1252 -*-
import time

huh = time.time()
def kaksi(yksi):
	lista = []
	for a in range(2,int(yksi**0.5+1)):
		if yksi%a == 0:
			lista.append(yksi/a)
			lista.append(a)
	return lista

def palikat(q):
	kastraatio=[q]
	for i in kastraatio:
		lasta = kaksi(i)
		if len(lasta) == 0: continue
		for koosu in lasta:
			if kastraatio.count(koosu)==0: kastraatio.append(koosu)
	kastraatio.append(1)
	kolhoosi = 0
	return kastraatio
i = 1
koko = 0
while 1:
	koko += i
	moo = palikat(koko)
	i+=1
	if len(moo)>500:
		break
print moo[0], time.time()-huh
