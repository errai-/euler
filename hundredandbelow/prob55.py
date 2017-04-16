# -*- coding: cp1252 -*-
import time

oho = time.time()
def iterus(marsu,i=1):
	ahaa = 1
	if i == 50:
		ahaa = 1
	else:
		k = 1
		daphne = int(marsu[::-1])
		kuriiri = str(int(marsu) + daphne)
		if len(kuriiri)%2==0:
			if kuriiri[:len(kuriiri)/2]!=kuriiri[:len(kuriiri)/2-1:-1]: k = 0
		else:
			if kuriiri[:len(kuriiri)/2]!=kuriiri[:len(kuriiri)/2:-1]: k = 0
		if k == 1: ahaa = 0
		if k == 0:
			ahaa = iterus(kuriiri,i+1)
	return ahaa
juoksee = 0
for munaus in range(1,10000):
	joo = iterus(str(munaus))
	juoksee += joo
print juoksee,time.time()-oho
