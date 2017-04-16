# -*- coding: cp1252 -*-
import time
from fractions import Fraction

def jaot(a,e):
	koo = []
	for j in range(10,10*a[0]+a[1]):
		c,d = [],j/10
		c.append(d)
		c.append(j-d*10)
		if e == 1 and c[1] == 0: continue
		for kaa in range(2):
			for baa in range(2):
				if a[kaa] == c[baa]:
					gasp,gasr,gons=[],[],[]
					gasp.extend(a)
					gasr.extend(c)
					gasp.pop(kaa)
					gasr.pop(baa)
					if gasp[0]!=0: gons.extend(gasr); gons.extend(gasp) 
					b = 10*a[0]+a[1]
					daa = Fraction(j,b)
					if gasp[0]!=0: doo = Fraction(gasr.pop(0),gasp.pop(0))
					else: doo = 0
					if daa == doo: koo.append(daa)
	return koo
gaa = []
for i in range(10,100):
	e = 0
	a,b = [],i/10
	a.append(b)
	a.append(i-b*10)
	if a[1] == 0: e = 1
	gaa.extend(jaot(a,e))
o = 1
for d in gaa:
	o*=d
print 1/o
