# -*- coding: cp1252 -*-
import time

viisas = time.time()

def primes(luukku):
	if luukku%2 == 0:
		luukku = 0
	else:
		for i in range(3,int(luukku**0.5+1),2):
			if luukku%i == 0: luukku = 0; break
	return luukku	

def perms(luukku,joo=''):
	paluu = []
	if luukku == '':
		if primes(int(joo))!=0:
			if len(str(int(joo))) == 4: paluu.append(int(joo));
	else:
		for cee in range(len(luukku)):
			muu = luukku
			joo += luukku[cee]
			das = luukku[:cee]+luukku[cee+1:]
			paluu.extend(perms(das,joo))
			joo = joo[:len(joo)-1]
	return paluu
laatikko = []
for a in range(1000,10000):
	if primes(a)!=0:
		koo = perms(str(a))
		if len(koo)>=3: 
			koo.sort() 
			if koo not in laatikko:
				laatikko.append(koo)
laatikko.sort()
lotushetki = []
for aapinen in range(len(laatikko)):
	kasparov = laatikko[aapinen]
	kamal = len(kasparov)
	for beeta in range(kamal):
		doo = kasparov.pop(0)
		for jaha in kasparov:
			olaf = jaha - doo
			vee = jaha + olaf
			if olaf == 0: continue
			if vee in kasparov:
				if [vee-2*olaf,vee-olaf,vee] not in lotushetki:
						lotushetki.append([vee-2*olaf,vee-olaf,vee])
print lotushetki,time.time()-viisas # amurrrr!

