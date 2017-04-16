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
			if kastraatio.count(koosu)==0: kastraatio.extend(lasta)
	kastraatio.append(1)
	kolhoosi = 0
	kastraatio.pop(0)
	for i in kastraatio:
		kolhoosi += i
	return kolhoosi
uuslist = []
for moo in range(1,10000):
	kaktus = palikat(moo)
	if kaktus!= moo:
		if palikat(kaktus) == moo:
			if uuslist.count(moo)==0: uuslist.append(moo)
			if uuslist.count(kaktus)==0: uuslist.append(kaktus)
pee = 0
for i in uuslist: pee += i
print pee, time.time()-huh #koht. ruma ratkaisu, mutta now we're back in the U.S.S.R.!
