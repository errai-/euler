# -*- coding: cp1252 -*-
import time

qaw = time.time()

def trunkkaus(kaasua):
	p = 1
	for i in range(1,len(kaasua)):
		a = isprime(int(kaasua[i:]))
		if a == 0: p = 0; break
	if p == 1:
		for b in range(1,len(kaasua)):
			c = isprime(int(kaasua[:b]))
			if c == 0: p = 0; break
	return p

def isprime(a):
	q = 1
	if a == 2: q = 1
	elif a%2 == 0: q = 0
	elif a == 1: q = 0
	else: 
		for i in range(3,int(a**0.5+1),2):
			if a%i == 0: q = 0
	return q

def annos(pota):
	luut = []
	for a in range(10**pota,10**(pota+1)):
		if isprime(a) == 1: luut.append(str(a))
	return luut

tolot,tulot,juoksija = 0,0,10
while tulot!=11:
	if isprime(juoksija) == 1:
		if trunkkaus(str(juoksija)) == 1: tolot+=juoksija; tulot+=1
	juoksija += 1
print tolot,time.time()-qaw
