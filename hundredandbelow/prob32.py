# -*- coding: cp1252 -*-
import time

def onko(luumu):
	suu = []
	for i in range(2,int(luumu**0.5)+1):
		seos = 1
		y,b,joo = str(luumu/i),str(i),str(luumu)
		for moh in y: suu.append(int(moh))
		for goh in b: suu.append(int(goh))
		for doh in joo: suu.append(int(doh))
		for q in suu: 
			if suu.count(q)!=1: seos = 0
		if seos == 1: break
	if seos == 1: return luumu
	else: return 0

e,on = 4,0
while e < 60:
	print e
	on+=onko(e)
	e+=1
print on
