# -*- coding: cp1252 -*-
import time

kooo = time.time()
def kaksi(a):
	laa = []
	for i in range(2,int(a**0.5+1)):
			if a%i == 0 and laa.count(i) == 0:
				laa.append(i)
				if a/i!= i: laa.append(a/i)
	laa.append(1)
	return laa

roos,vrt,qrt,suu = [],[],[],0
for i in range(1,28124):
	boo,sooma = kaksi(i),0
	for doo in boo:
		sooma += doo
	if sooma > i:
		roos.append(i)
	vrt.append(1)
roos.sort()
for a in range(len(roos)):
	if roos[a]>14062: break
	for b in range(a,len(roos)):
		o = roos[a]+roos[b]
		if o>28123: break
		vrt[o-1] = 0
		
for a in range(len(vrt)):
	if vrt[a]==1: suu+=a+1
print suu,time.time()-kooo

