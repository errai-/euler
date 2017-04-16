# -*- coding: cp1252 -*-
import time

digits = [9,8,7,6,5,4,3,2,1]

def isprime(listb):
	b = 0
	for a in range(len(listb)):
		b += listb[a]*(10**(len(listb)-a-1))
	if b%2 == 0: b = 0
	else: 
		for kaa in range(3,int(b**0.5+1),2):
			if b%kaa == 0: b = 0; break
	return b

def permutations(listb,listd):
	if listd == []:
		ooo = isprime(listb)
		if ooo != 0: print listb
		
	for a in range(len(listd)):
		listc,lista = [],[]
		listc.extend(listd)
		lista.extend(listb)
		lista.append(listc.pop(a))
		permutations(lista,listc)


permutations([],digits[2:]) # manuaalinen luonnos, oltu tyhmiä, ÄLÄ OLE TYMÄ!.
