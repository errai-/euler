# -*- coding: cp1252 -*-
import time
alef = time.time()

def onko(a):
	koo = 0
	if (int(len(str(a))/2))*2 == len(str(a)): 
		doo = str(a)[:len(str(a))/2]
		daa = str(a)[:len(str(a))/2-1:-1]
		if doo == daa: koo = a
	else: 
		doo = str(a)[:len(str(a))/2]
		daa = str(a)[:len(str(a))/2:-1]
		if doo == daa: koo = a
	return koo
suumos = 0
for i in range(1,978):
# ei huomioi tapausta, jossa välissä ei ol' ollenkaan numeroita - oikeastaan väliä 011 = 3	
# alla, käsiteltävä i = 1 ja i = 2 erikseen. bin(2) = 10 ei ole palindromi, mutta bin(1) on,
# samoin kuin 1, lisättävä summaan ykkönen
	a = int('0b'+bin(i)[2:]+bin(i)[:1:-1],2)
	b = int('0b'+bin(i)[2:]+'1'+bin(i)[:1:-1],2)
	c = int('0b'+bin(i)[2:]+'0'+bin(i)[:1:-1],2)
	if a>1000000: break
	suumos += onko(a)
	if b<1000000: suumos += onko(b)
	if c<1000000: suumos += onko(c)
suumos+=1
print time.time()-alef,suumos
