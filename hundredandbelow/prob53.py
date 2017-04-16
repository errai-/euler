# -*- coding: cp1252 -*-
import time

fagotto = time.time()
def magenta(a):
	d = 1
	for dasoo in range(1,a+1):
		d*=dasoo
	return d

i = 22
ee = 0
while i < 101:
	doo = magenta(i)
	for boot in range(1,i-1):
		moo,loo = magenta(boot),magenta(i-boot)
		rastafari = float(doo)/float(moo*loo)
		if rastafari > 1000000: ee += 1
	i+=1
print ee,time.time()-fagotto
