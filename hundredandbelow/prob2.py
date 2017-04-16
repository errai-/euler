# -*- coding: cp1252 -*-


l, p, e = 0, 1, 1
while p <= 4*10**6:
	if p%2 == 0:
		l = l + p
	p, e = p + e, p
print l

