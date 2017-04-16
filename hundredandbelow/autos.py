# -*- coding: cp1252 -*-
import time

paatos = [1,2,3,4,5,6,7,8,9]
suma = 0
sahajaos = time.time()

def vaasa(lista1,a):
	if a == 4396: print 4396
	k = 0
	for bakshal in range(2,int(a**0.5+1)):
		if a%bakshal == 0:
			k = 1
			lasta = []
			lasta.extend(lista1)
			for gaa in str(bakshal):
				if lasta.count(int(gaa))==1:
					lasta.remove(int(gaa))
				else: k = 0
			for ggoo in str(a/bakshal):
				if lasta.count(int(ggoo))!=1:
					k = 0
				else: lasta.remove(int(ggoo))
			if len(lasta)!=0: k = 0
		if k == 1: break
	if k==1: 
		return a

	if k==0: return 0

def onko(lista1,lista2,a=0):
	tulos = 0
	if lista2 == []:
		tulos = vaasa(lista1,a)
	else:
		for i in range(len(lista2)):
			lasta2 = []
			lasta2.extend(lista2)
			b = lasta2.pop(i)
			a += (10**(len(lista2)-1))*b
			tulos += onko(lista1,lasta2,a)
			a -= (10**(len(lista2)-1))*b
	return tulos

def valinta(lista1,lista2,i):
	koro = 0
	if i == 0:
		koro += onko(lista1,lista2)
	else:
		for o in range(len(lista1)):
			lasta1,lasta2 = [],[]
			lasta1.extend(lista1)
			lasta2.extend(lista2)
			lasta2.append(lasta1.pop(o))
			koro += valinta(lasta1,lasta2,i-1)
	return koro

for o in range(9):
	lista1,lista2 = [],[]
	lista1.extend(paatos)
	lista2.append(lista1.pop(o))
	suma += valinta(lista1,lista2,3)
print suma/24 # ei, ei, ei!!!!
