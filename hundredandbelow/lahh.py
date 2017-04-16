# -*- coding: cp1252 -*-
import time

def vaasa(lista1,a):
	k = 0
	for bakshal in range(2,int(a**0.5+1)):
		print bakshal
		if a%bakshal == 0:
			if bakshal == 39 and a == 7254: print a 
			k = 1
			lasta = []
			lasta.extend(lista1)
			for gaa in str(bakshal):
				if lasta.count(int(gaa))==1:
					lasta.remove(int(gaa))
				else: k = 0;
			for ggoo in str(a/bakshal):
				if lasta.count(int(ggoo))!=1:
					k = 0;
				else: lasta.remove(int(ggoo))
			if len(lasta)!=0: k = 0
		if k == 1: break
	if k==1: print a; return a
	if k==0: return 0

print vaasa([1,3,6,8,9],7254)

