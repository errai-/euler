# -*- coding: cp1252 -*-
import time
def isprime(laavaa):
	for kamal in range(2, int(laavaa**.5 + 1)):
		if laavaa%kamal == 0:
			return False
			laavaa = 0
			break
	if laavaa != 0:
		return True
s = time.time()
mus = 0
suu = 2
while suu<2*10**6:
	if isprime(suu):
		mus = suu + mus
		print suu
	suu += 1
print mus
print time.time() -s
