# -*- coding: cp1252 -*-
import time

qaw = time.time()

def isprime(a):
	q = 1
	if a%2 == 0: q = 0
	elif a == 1: q = 0
	else: 
		for i in range(3,int(a**0.5+1),2):
			if a%i == 0: q = 0
	return q

def rlroo(ahaa,pahaa):
	nauru,korsu = [],[]
	for qorso in pahaa:
		for i in range(1,10):
			oo = str(i)+qorso
			if isprime(int(oo)) == 1: nauru.append(oo)
	for torso in ahaa:
		for b in range(1,10):
			moo = torso+str(b)
			if isprime(int(moo)) == 1: korsu.append(moo)
	return korsu,nauru

luumu = luu = ['2','3','5','7']
lasta,losta = 0,0
while losta!=11:
	luumu,luu = rlroo(luumu,luu)
	for a in luumu:
		for b in luu:
			if a==b: lasta+=int(a);losta+=1
	print lasta

	
print time.time()-qaw,lasta
