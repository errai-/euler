# -*- coding: cp1252 -*-
import time

kasparov = time.time()
a,b,l = 1,0,1
while 1:
	b = b+a
	l += 1
	if b >= 10**999:
		print l
		break
	a = b+a
	l += 1
	if a >= 10**999:
		print l
		break
print time.time()-kasparov
