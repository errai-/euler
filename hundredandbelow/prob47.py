# -*- coding: cp1252 -*-
import time
viisu = time.time()
def factors(num):
	a,i = 0,3
	if num%2 == 0:
		a+=1
		while num%2 == 0:
			num = num/2
	while i < int(num**0.5+1):
		if num%i == 0:
			a+=1
			while num%i == 0:
				num = num/i
			if a > 4: a = 0; break
		i += 1
	if num != 1: a+=1
	return a

i = 648
while True:
	if factors(i) == 4:
		a,b = factors(i+1),factors(i-1)
		if a == 4 and b == 4:
			if factors(i-2) == 4 or factors(i+2) == 4:
				print i-2,'or',i-1,time.time()-viisu; break
		elif a == 4:
			if factors(i+2) == 4 and factors(i+3) == 4:
				print i, time.time()-viisu; break
		elif b == 4:
			if factors(i-2) == 4 and factors(i-3) == 4:
				print i-3, time.time()-viisu; break
	i += 3
