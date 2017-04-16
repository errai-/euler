# -*- coding: cp1252 -*-
import time

maaaaaaaaa =time.time()

def isprime(oo):
	if oo%2 == 0: oo = 0
	else:
		for i in range(3,int(oo*0.5+1),2):
			if oo%i == 0: oo = 0; break
	return oo

i,primes = 3,[2]
while i<45863:
	k = 1
	for a in range(3,int(i**0.5+1),2):
		if i%a == 0: k = 0
	if k == 1: primes.append(i)
	i += 2
a,i = 0,0
while a < 1000000:
	a+=primes[i]
	i += 1
tulot = []
i-=2
a-=primes[i+1]
b,j = a,i
while isprime(a) == 0:
	a -= primes[i]
	i -= 1
tulot.append([a,i])
for ost in range(0,11):
	b -= primes[ost]
	a,i = b,j
	while isprime(a) == 0:
		a -= primes[i]
		i -= 1
	tulot.append([a,i-ost-1])
vrt = 0
for listb in tulot:
	if listb[1]>vrt: vrt = listb[1]; joo = listb[0]
print joo, time.time() - maaaaaaaaa # ruma, mutta ratkeaa
