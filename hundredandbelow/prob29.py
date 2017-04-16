# -*- coding: cp1252 -*-
import time

wee = time.time()
l = []
for i in range(2,101):
	for qoo in range(2,101):
		d = i**qoo
		if l.count(d)==0: l.append(d)
print len(l),time.time()-wee
