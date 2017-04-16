# -*- coding: cp1252 -*-
import time


daw = time.time()
def muuntaja(daavid):
	hoo,i = str(daavid),1
	while len(hoo)<9:
		i += 1
		hoo += str(i*daavid)
	if len(hoo)>9: hoo = 0
	else:
		gasp = [0]*9
		for a in hoo:
			if gasp[int(a)-1]!=0:
				hoo = 0; break
			else: gasp[int(a)-1]+=1
		hoo = int(hoo)
	return hoo
joo = 0
for i in range(4):
	for b in range((10**i)):
		k = 0
		doo = [0]*9
		daavid = b + 9*(10**i)
		for mooses in str(daavid):
			if doo[int(mooses)-1]!=0:
				k = 1; break
			else: doo[int(mooses)-1]+=1
		if k == 1: continue
		jaa = muuntaja(daavid)
		if jaa != 0: 
			if joo > jaa: joo = jaa
print joo, time.time()-daw
		
