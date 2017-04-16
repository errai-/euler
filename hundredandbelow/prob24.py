# -*- coding: cp1252 -*-
import time
laa = time.time()
def factorial(stringi):
	for i in range(len(stringi)):
		koostumus = 1
		for a in range(1,int(stringi[i])+1):
			koostumus*=a
	return koostumus
numpers,liisata,kok,luku1,luku2=[0,1,2,3,4,5,6,7,8,9],[],1000000,0,0
for i in range(10):
	f = factorial(str(9-i))
	liisata.append(int(kok/f))
	kok -= int(kok/f)*f
for i in range(10):
	luku2 += (numpers[liisata[i]])*(10**(9-i))
for i in range(10):
	luku1 += (numpers.pop(liisata.pop(0)))*(10**(9-i))
print luku2, '\n', luku1, time.time()-laa
		
