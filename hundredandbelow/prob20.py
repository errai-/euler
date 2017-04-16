# -*- coding: cp1252 -*-

luku = str(2**1000)
huuhaa = 0
for tajmahal in range(len(luku)):
	huuhaa += int(luku[tajmahal])
print huuhaa
def pilkkoja(luku):
	palikat = [luku]
	coo = 2
	while True:
		for a in palikat:
			for x in range (2,int(luku**0.5)+1):
				if a%x != 0: continue
				else: 
					palikat.remove(a)
					palikat.append(x)
					palikat.append(luku/x)
					coo = 2
					break
		if coo == 1: break	
	palikat.sort()
	return palikat
print pilkkoja(20)
print luku
