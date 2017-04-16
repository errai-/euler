# -*- coding: cp1252 -*-
import time

i,tulos = 145,0
while tulos == 0:
	talos = i*(2*i-1)
	a = float((1 + 24*talos)**0.5)
	if a == int(a):
		if a%6 == 5:
			b = float((1 + 8*talos)**0.5)
			if b == int(b):
				if b%2 == 1:
					tulos = talos
				else: i+=1; continue
			else: i+=1; continue
		else: i+=1; continue
	else: i+=1; continue
print tulos
