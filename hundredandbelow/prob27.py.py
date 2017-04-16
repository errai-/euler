# -*- coding: cp1252 -*-
import time

def giveprime(luku):
	haa = luku + 1
	while 1:
		if isprime(haa)==1: break
		haa += 1
	return haa

def isprime(luku):
	i,b = 2,1
	while i <= sqrt(luku)
		if luku%i == 0: b=0;break
		i+=1
	return b

print giveprime(4)
