# -*- coding: cp1252 -*-
import time
wc = time.time()
def factorial(stringi):
	painija = 0
	for i in range(len(stringi)):
		koostumus = 1
		for a in range(1,int(stringi[i])+1):
			koostumus*=a
		painija+=koostumus
	if painija == int(stringi):return painija
	else: return 0
moo = -3
for i in range(1,100000):
	moo += factorial(str(i)) #oletus: ei enempää
print moo,time.time()-wc

