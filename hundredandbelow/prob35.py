# -*- coding: cp1252 -*-
import time

def korva(nani,ne):
	for a in range(3,int(nani**0.5)+1,2):
		if nani%a == 0:
			ne = 0
			break
	return ne
	
	
dew,suu = time.time(),0
def ympura(ne):
	for i in range(1,len(ne)):
		kaa = int(ne[i:]+ne[:i])
		if kaa%2 == 0: ne = 0; break
		else:
			ne = korva(kaa,ne)
			if ne == 0: break
			else: continue
		if ne == 0: break
	return int(ne)

def primes(poo):
	if poo%2 == 0: poo = 'nej!'
	else:
		for i in range(3,int(poo**0.5+1),2):
			if poo%i == 0: poo = 'njet'; break
		if poo!='njet':
			poo = ympura(str(poo))
	return poo

oolist = [2]
for a in range(3,1000000):
	doo = primes(a)
	if doo==a:oolist.append(a)
print time.time()-dew,len(oolist),oolist # turhan pitkä
