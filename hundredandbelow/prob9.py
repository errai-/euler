# -*- coding: cp1252 -*-


for i in range(1,500):
	x = (float(1000*i)/float(500+i))
	if x%1 == 0:
		y = 500-i
		break
print x*y*(1000-x-y)
